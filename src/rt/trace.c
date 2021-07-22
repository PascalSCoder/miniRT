/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trace.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 11:00:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:44:23 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include <math.h>

/*
**	Forward each object in objects to the intersections function.
**	Keeps track of the nearest intersection point. (if any)
*/
char	trace(t_list *objects, t_ray *ray)
{
	double	t;

	ray->obj = 0;
	ray->t = INFINITY;
	while (objects)
	{
		if (intersections(ray->origin, ray->dir, objects->element, &t))
		{
			if (t < ray->t)
			{
				ray->obj = objects->element;
				ray->t = t;
			}
		}
		objects = objects->next;
	}
	if (ray->obj)
	{
		ray->p = v3_add(ray->origin, v3_multiply(ray->dir, ray->t));
		ray->n = get_obj_normal(get_obj_type(ray->obj), ray);
		return (1);
	}
	return (0);
}
