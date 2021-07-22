/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_unit_normalize.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:57:44 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:17:25 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"
#include <math.h>

/*
**	Used to rotate a vector.
**	Returns the quaternion result of multiplying q1 vect with it's scalar.
*/
t_quat	quat_unit_normalize(t_quat q1)
{
	double	angle;

	angle = deg_to_rad(q1.s);
	q1.vect = v3_normalize(q1.vect);
	q1.s = cosf(angle * .5f);
	q1.vect = v3_multiply(q1.vect, sinf(angle * .5f));
	return (q1);
}
