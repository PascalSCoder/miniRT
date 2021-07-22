/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   square_is.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 11:41:59 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:26:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include <math.h>

static void	set_points(t_square *square, t_vector3 ps[4])
{
	t_matrix4	trnsfrm;

	trnsfrm = m4_from_orient(square->orientation, square->position);
	ps[0] = v3_transform_m4(v3_new(-square->size / 2, square->size / 2, 0),
			trnsfrm);
	ps[1] = v3_transform_m4(v3_new(square->size / 2, square->size / 2, 0),
			trnsfrm);
	ps[2] = v3_transform_m4(v3_new(square->size / 2, -square->size / 2, 0),
			trnsfrm);
	ps[3] = v3_transform_m4(v3_new(-square->size / 2, -square->size / 2, 0),
			trnsfrm);
}

t_vector3	square_normal(t_ray *hit)
{
	return (calc_normaldir(((t_square *)hit->obj)->orientation,
			v3_subtract(hit->p, hit->origin)));
}

char	check_angles(t_vector3 p[4], t_vector3 hitp)
{
	t_vector3	v[8];

	v[0] = v3_subtract(p[1], p[0]);
	v[1] = v3_subtract(p[2], p[1]);
	v[2] = v3_subtract(p[3], p[2]);
	v[3] = v3_subtract(p[0], p[3]);
	v[4] = v3_subtract(hitp, p[0]);
	v[5] = v3_subtract(hitp, p[1]);
	v[6] = v3_subtract(hitp, p[2]);
	v[7] = v3_subtract(hitp, p[3]);
	if (v3_dot(v3_normalize(v[0]), v3_normalize(v[4])) >= 0)
		if (v3_dot(v3_normalize(v[1]), v3_normalize(v[5])) >= 0)
			if (v3_dot(v3_normalize(v[2]), v3_normalize(v[6])) >= 0)
				if (v3_dot(v3_normalize(v[3]), v3_normalize(v[7])) >= 0)
					return (1);
	return (0);
}

char	square_is(t_vector3 origin, t_vector3 dir, t_square *square, double *t)
{
	t_plane		pl;
	t_vector3	points[4];
	t_vector3	hitp;

	pl.orientation = square->orientation;
	pl.position = square->position;
	if (!plane_is(origin, dir, &pl, t))
		return (0);
	set_points(square, points);
	hitp = v3_add(v3_multiply(dir, *t), origin);
	return (check_angles(points, hitp));
}
