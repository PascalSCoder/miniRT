/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 16:10:27 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/03 15:17:27 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/gmath.h"
#include "../public/rt.h"
#include "../public/errors.h"
#include <stdio.h>
#include <stdlib.h>

void	printrgb(t_rgb rgb, char *prefix)
{
	if (!prefix)
		prefix = "Rgb";
	printf("%s: %hhu, %hhu, %hhu\n", prefix, rgb.r, rgb.g, rgb.b);
}

void	printv3(t_vector3 vect, char *prefix)
{
	if (!prefix)
		prefix = "Vector3";
	printf("%s: %f, %f, %f\n", prefix, vect.x, vect.y, vect.z);
}

void	printfrgb(t_frgb rgb, char *prefix)
{
	if (!prefix)
		prefix = "Frgb";
	printf("%s: %f, %f, %f\n", prefix, rgb.r, rgb.g, rgb.b);
}

t_ray	*debugray(t_scene *scene, int x, int y)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		program_exit(err_system, 0);
	ray->origin = scene->active_cam->position;
	ray->dir = v3_normalize(view_to_world(scene, x, y));
	trace(scene->objects, ray);
	return (ray);
}

int	mb_pressed(int button, int x, int y, void *param)
{
	t_scene	*scene;
	t_ray	*ray;

	scene = (t_scene *)param;
	if (!scene->debug)
		return (0);
	if (button == 1)
	{
		ray = debugray(scene, x, y);
		if (!ray->obj)
			printf("Debug ray missed.\n");
		else
		{
			printf("Hit obj type: %d\n", get_obj_type(ray->obj));
			printf("distance: %f\n", ray->t);
			printv3(ray->n, "normal");
			printv3(ray->p, "point");
			printv3(ray->dir, "direction");
			printf("angle: %f\n", v3_dot((ray->n), ray->dir));
		}
		free(ray);
	}
	return (0);
}
