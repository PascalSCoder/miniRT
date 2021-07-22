/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_mult.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:55:21 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:30:52 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

#include "../../public/debug.h"

/*
**	Returns the quaternion result of multiplying q1 with q2.
*/
t_quat	quat_mult(t_quat q1, t_quat q2)
{
	t_quat		q3;

	q3.s = q1.s * q2.s - v3_dot(q1.vect, q2.vect);
	q3.vect = v3_multiply(q2.vect, q1.s);
	q3.vect = v3_add(q3.vect, v3_multiply(q1.vect, q2.s));
	q3.vect = v3_add(q3.vect, v3_cross(q1.vect, q2.vect));
	return (q3);
}
