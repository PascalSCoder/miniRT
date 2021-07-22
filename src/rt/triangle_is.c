/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle_is.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 11:51:11 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:34:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

t_vector3	triangle_normal(t_ray *hit)
{
	t_vector3	A;
	t_vector3	B;
	t_vector3	n;
	t_triangle	*tr;

	tr = (t_triangle *)hit->obj;
	A = (v3_subtract(tr->p1, tr->p0));
	B = (v3_subtract(tr->p2, tr->p0));
	n = v3_normalize(v3_cross(A, B));
	if (v3_dot(n, hit->dir) <= 0)
		return (n);
	else
		return (v3_multiply(n, -1));
}

static char	check_angles(t_triangle *tr, t_vector3 hitp, t_vector3 n)
{
	t_vector3	edge;
	t_vector3	hitpv;

	edge = v3_subtract(tr->p1, tr->p0);
	hitpv = v3_subtract(hitp, tr->p0);
	if (v3_dot(n, v3_cross(edge, hitpv)) < 0)
		return (0);
	edge = v3_subtract(tr->p2, tr->p1);
	hitpv = v3_subtract(hitp, tr->p1);
	if (v3_dot(n, v3_cross(edge, hitpv)) < 0)
		return (0);
	edge = v3_subtract(tr->p0, tr->p2);
	hitpv = v3_subtract(hitp, tr->p2);
	if (v3_dot(n, v3_cross(edge, hitpv)) < 0)
		return (0);
	return (1);
}

char	triangle_is(t_vector3 origin, t_vector3 dir, t_triangle *tr, double *t)
{
	t_vector3	A;
	t_vector3	B;
	t_vector3	normal;
	t_plane		pl;
	t_vector3	hitp;

	A = v3_subtract(tr->p1, tr->p0);
	B = v3_subtract(tr->p2, tr->p0);
	normal = v3_cross(A, B);
	pl.orientation = normal;
	pl.position = tr->p0;
	if (!plane_is(origin, dir, &pl, t))
		return (0);
	hitp = v3_add(v3_multiply(dir, *t), origin);
	return (check_angles(tr, hitp, normal));
}
