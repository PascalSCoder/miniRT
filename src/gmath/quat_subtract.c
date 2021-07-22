/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_subtract.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:54:42 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:17:31 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the quaternion result of subtracting q2 from q1.
*/
t_quat	quat_subtract(t_quat q1, t_quat q2)
{
	q1.s -= q2.s;
	q1.vect = v3_subtract(q1.vect, q2.vect);
	return (q1);
}
