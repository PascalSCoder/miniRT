/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_add.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:55:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:18:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the quaternion result of adding q2 to q1.
*/
t_quat	quat_add(t_quat q1, t_quat q2)
{
	q1.s += q2.s;
	q1.vect = v3_add(q1.vect, q2.vect);
	return (q1);
}
