/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_normalize.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:57:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:17:44 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns quaternion q1 normalized.
**	Edge case magn = 0 might need to be evaded.
*/
t_quat	quat_normalize(t_quat q1)
{
	double	magn;
	double	s;

	magn = quat_magnitude(q1);
	if (magn == 0)
		return (q1);
	s = 1 / magn;
	q1.s *= s;
	q1.vect = v3_multiply(q1.vect, s);
	return (q1);
}
