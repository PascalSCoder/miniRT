/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:19:30 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:13:53 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_vector3	v3_rotate(t_vector3 vect, double angle, t_vector3 axis)
{
	t_quat	p;
	t_quat	q;
	t_quat	result;

	p.s = 0;
	p.vect = vect;
	axis = v3_normalize(axis);
	q = quat_new(axis, angle);
	result = quat_mult(q, p);
	result = quat_mult(result, quat_inverse(q));
	return (result.vect);
}
