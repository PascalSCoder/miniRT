/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_scalar_mult.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:55:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:17:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the quaternion result of multiplying q1 with scalar value.
*/
t_quat	quat_mult_scalar(t_quat q1, double scalar)
{
	q1.s *= scalar;
	q1.vect = v3_multiply(q1.vect, scalar);
	return (q1);
}
