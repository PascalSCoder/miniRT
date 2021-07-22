/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shading.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 18:24:06 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/10 13:23:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include "../../public/gmath.h"

#include <math.h>

static t_frgb	shade_ambient(t_ambient ambient, t_frgb obj_rgb)
{
	t_frgb	rgb;

	rgb = frgb_mult(ambient.rgb, ambient.luminosity);
	rgb = frgb_mult_frgb(rgb, obj_rgb);
	return (rgb);
}

static t_frgb	shade_spot(void *objects, t_spotlight *light, t_ray *hit)
{
	t_ray	shadowray;
	double	luminosity;
	double	magnitude;
	double	angle;
	t_frgb	rgb;

	shadowray.origin = v3_add(hit->p, v3_multiply(hit->n, 0.0001f));
	shadowray.dir = v3_normalize(v3_subtract(light->position, hit->p));
	magnitude = v3_magnitude(v3_subtract(light->position, hit->p));
	luminosity = light->luminosity - (magnitude / 250);
	if (luminosity <= 0)
		return (frgb_new(0, 0, 0));
	if (trace(objects, &shadowray) && shadowray.t < magnitude)
		return (frgb_new(0, 0, 0));
	angle = v3_dot(shadowray.dir, hit->n);
	if (angle < 0)
		angle = 0.f;
	rgb = frgb_mult(light->rgb, luminosity * angle);
	rgb = frgb_mult_frgb(get_obj_color(hit->obj), rgb);
	return (rgb);
}

static t_frgb	shade_dir(void *objects, t_dirlight *light, t_ray *hit)
{
	t_frgb	rgb;
	double	angle;
	t_ray	shadowray;

	shadowray.dir = v3_normalize(v3_multiply(light->dir, -1));
	shadowray.origin = v3_add(hit->p, v3_multiply(hit->n, 0.0001f));
	if (trace(objects, &shadowray))
		return (frgb_new(0, 0, 0));
	angle = v3_dot(shadowray.dir, hit->n);
	if (angle < 0)
		angle = 0.f;
	rgb = frgb_mult(light->rgb, light->luminosity * angle);
	rgb = frgb_mult_frgb(get_obj_color(hit->obj), rgb);
	return (rgb);
}

static t_frgb	shade_roughness(t_scene *scene, t_ray *hit, int depth)
{
	t_ray		ray;
	t_physmat	mat;
	t_frgb		c1;
	t_frgb		c2;

	mat = *get_obj_physmat(hit->obj);
	c1 = frgb_mult(get_obj_color(hit->obj), mat.roughness);
	if (mat.roughness < 1)
	{
		ray.dir = v3_reflect(hit->dir, hit->n);
		ray.origin = v3_add(hit->p, v3_multiply(hit->n, 0.0001f));
		if (trace(scene->objects, &ray))
		{
			c2 = frgb_mult(shade(scene, &ray, depth + 1), 1 - mat.roughness);
			return (frgb_add(c1, c2));
		}
	}
	return (c1);
}

t_frgb	shade(t_scene *scene, t_ray *hit, int depth)
{
	t_frgb		rgb;
	t_list		*light;
	t_physmat	*physmat;

	if (depth >= scene->max_depth + 1)
		return (frgb_new(0, 0, 0));
	physmat = get_obj_physmat(hit->obj);
	if (physmat)
		return (shade_roughness(scene, hit, depth));
	rgb = shade_ambient(scene->ambient, get_obj_color(hit->obj));
	light = scene->lightsrcs;
	while (light)
	{
		if (*(t_lt_type *)light->element == lt_dir)
			rgb = frgb_add(rgb, shade_dir(scene->objects, light->element, hit));
		else if (*(t_lt_type *)light->element == lt_spot)
			rgb = frgb_add(rgb, shade_spot(scene->objects,
						light->element, hit));
		light = light->next;
	}
	return (rgb);
}
