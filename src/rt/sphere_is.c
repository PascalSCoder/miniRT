/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere_is.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/06 13:07:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 11:32:08 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include <math.h>

t_vector3	sphere_normal(t_ray *hit)
{
	t_vector3	n;

	n = v3_normalize(v3_subtract(hit->p, ((t_sphere *)hit->obj)->position));
	return (calc_normaldir(n, hit->dir));
}

/*
**	Sphere intersection test in an analytic approach.
*/
char	sphere_is(t_vector3 origin, t_vector3 dir, t_sphere *sphere, double *t)
{
	t_vector3	L;
	double		a;
	double		b;
	double		c;

	L = v3_subtract(origin, sphere->position);
	a = v3_dot(dir, dir);
	b = 2 * v3_dot(dir, L);
	c = v3_dot(L, L) - sphere->diameter2;
	return (solve_quadr_eq(a, b, c, t));
}
