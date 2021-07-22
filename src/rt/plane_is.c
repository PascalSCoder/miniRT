/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane_is.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 14:00:59 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/10 13:24:03 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include <math.h>

t_vector3	plane_normal(t_ray *hit)
{
	return (calc_normaldir(((t_plane *)hit->obj)->orientation,
			v3_subtract(hit->p, hit->origin)));
}

static double	dabs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char	plane_is(t_vector3 origin, t_vector3 dir, t_plane *plane, double *t)
{
	double		d;
	t_vector3	v;

	d = v3_dot(plane->orientation, dir);
	if (dabs(d) > 0.0001f)
	{
		v = v3_subtract(plane->position, origin);
		*t = v3_dot(v, plane->orientation) / d;
		if (*t >= 0)
			return (1);
	}
	return (0);
}
