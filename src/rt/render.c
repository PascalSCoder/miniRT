/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 12:40:53 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 13:09:00 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include <math.h>
#include <stdlib.h>

t_frgb	color_trace(t_scene *scene, t_ray ray)
{
	if (trace(scene->objects, &ray))
		return (shade(scene, &ray, 0));
	else
		return (scene->bg_color);
}

static t_vector2	v2_add(t_vector2 a, t_vector2 b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_frgb	aa_handle(t_scene *scene, t_vector2 p)
{
	t_frgb		*colors;
	int			v;
	int			h;
	t_vector2	p2;

	if (scene->aalias.samplec == 1)
		return (color_trace(scene, ray_new(scene, p)));
	colors = malloc(scene->aalias.samplec * sizeof(t_frgb));
	if (!colors)
		program_exit(err_system, 0);
	v = 0;
	while (v < scene->aalias.subdivc)
	{
		h = 0;
		while (h < scene->aalias.subdivc)
		{
			p2 = v2_add(scene->aalias.subdiv_table
				[(v * scene->aalias.subdivc) + h], p);
			colors[(v * scene->aalias.subdivc) + h]
				= color_trace(scene, ray_new(scene, p2));
			h++;
		}
		v++;
	}
	return (frgb_mix(colors, scene->aalias.samplec));
}

void	*render_thread(void *ptr)
{
	int			i;
	int			j;
	t_thread	*data;

	data = ptr;
	i = data->id;
	while (i < data->scene->res.height)
	{
		j = 0;
		while (j < data->scene->res.width)
		{
			data->frame[(i * data->scene->res.width) + j]
				= aa_handle(data->scene, (t_vector2){.x = j, .y = i});
			j++;
		}
		i += data->scene->threadc;
	}
	return (0);
}

t_frgb	*initstate_render(t_scene *scene)
{
	t_frgb	*frame;

	frame = ft_calloc(scene->res.height * scene->res.width, sizeof(t_frgb));
	if (!frame)
		program_exit(err_system, 0);
	create_threads(scene, frame);
	return (frame);
}
