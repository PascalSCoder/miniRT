/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_quadr_eq.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:22:25 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/26 15:15:29 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

static char	get_result(double s0, double s1, double *t)
{
	if (s1 > 0 && (s1 < s0 || s0 < 0))
		s0 = s1;
	if (s0 < 0)
		return (0);
	*t = s0;
	return (1);
}

char	solve_quadr_eq(double a, double b, double c, double *t)
{
	double	discriminant;
	double	s0;
	double	s1;
	double	q;

	discriminant = (b * b) - (4 * a * c);
	if (discriminant < 0)
		return (0);
	else if (discriminant == 0)
	{
		s0 = -0.5 * b / a;
		s1 = s0;
	}
	else
	{
		if (b > 0)
			q = -0.5 * (b + sqrt(discriminant));
		else
			q = -0.5 * (b - sqrt(discriminant));
		s0 = q / a;
		s1 = c / q;
	}
	return (get_result(s0, s1, t));
}
