/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_to_world.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 10:31:51 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:56:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

t_vector3	view_to_world(t_scene *scene, double x, double y)
{
	t_matrix4	mtrx;

	x -= scene->res.width / 2;
	y = scene->res.height / 2 - y;
	mtrx = m4_from_orient(scene->active_cam->orientation,
			scene->active_cam->position);
	return (v3_transform_m4(v3_new(x, y, scene->active_cam->focal_len), mtrx));
}

t_ray	ray_new(t_scene *scene, t_vector2 p)
{
	t_ray	ray;

	ray.dir = v3_normalize(view_to_world(scene, p.x, p.y));
	ray.origin = scene->active_cam->position;
	return (ray);
}
