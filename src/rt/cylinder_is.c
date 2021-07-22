/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_is.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/10 13:26:30 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/31 20:49:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"
#include <math.h>

double	dabs(double d)
{
	if (d < 0)
		d *= -1;
	return (d);
}

t_vector3	cylinder_normal(t_ray *hit)
{
	t_cylinder	*cy;
	t_vector3	p_on_line;
	t_vector3	cy_p_vect;

	cy = (t_cylinder *)hit->obj;
	cy_p_vect = v3_subtract(hit->p, cy->position);
	p_on_line = v3_multiply(cy->orientation,
			v3_dot(cy->orientation, cy_p_vect));
	if (v3_magnitude(p_on_line) + 0.0001f < cy->height)
		return (calc_normaldir(v3_normalize(v3_subtract(hit->p,
						v3_add(p_on_line, cy->position))), hit->dir));
	if (v3_magnitude(
			v3_subtract(cy_p_vect, cy->orientation)) <= v3_magnitude(cy_p_vect))
		return (calc_normaldir(cy->orientation, hit->dir));
	return (calc_normaldir(v3_multiply(cy->orientation, -1), hit->dir));
}

char	caps_is(t_vector3 origin, t_vector3 dir, t_cylinder *cy, double *t)
{
	double		t1;
	double		t2;
	t_circle	circle;

	circle.pl.orientation = cy->orientation;
	circle.pl.position = v3_add(cy->position,
			v3_multiply(cy->orientation, cy->height));
	circle.r = cy->diameter;
	if (!circle_is(origin, dir, &circle, &t1))
		t1 = -1;
	circle.pl.position = v3_add(cy->position,
			v3_multiply(cy->orientation, -cy->height));
	if (!circle_is(origin, dir, &circle, &t2))
		t2 = -1;
	if (t1 < 0)
		t1 = t2;
	if (t1 < 0)
		return (0);
	*t = t1;
	return (1);
}

char	finite_cy_is(t_vector3 origin, t_vector3 dir, t_cylinder *cy, double *t)
{
	double		a;
	double		b;
	double		c;
	t_vector3	tmp;
	t_vector3	v;

	tmp = v3_cross(dir, cy->orientation);
	a = v3_dot(tmp, tmp);
	v = v3_subtract(origin, cy->position);
	b = 2 * (v3_dot(v3_cross(v, cy->orientation),
				v3_cross(dir, cy->orientation)));
	tmp = v3_cross(v, cy->orientation);
	c = v3_dot(tmp, tmp) - (cy->diameter * cy->diameter);
	if (!solve_quadr_eq(a, b, c, t))
		return (0);
	tmp = v3_add(origin, v3_multiply(dir, *t));
	v = v3_subtract(tmp, cy->position);
	a = v3_dot(cy->orientation, v);
	if (dabs(a) < cy->height)
		return (1);
	return (0);
}

char	cylinder_is(t_vector3 origin, t_vector3 dir, t_cylinder *cy, double *t)
{
	double		dist[2];
	char		hit[2];
	double		d;

	d = -1;
	hit[0] = caps_is(origin, dir, cy, &dist[0]);
	hit[1] = finite_cy_is(origin, dir, cy, &dist[1]);
	if (hit[1])
		d = dist[1];
	if (hit[0] && (!hit[1] || dist[0] < dist[1]))
		d = dist[0];
	if (d >= 0)
	{
		*t = d;
		return (1);
	}
	return (0);
}
