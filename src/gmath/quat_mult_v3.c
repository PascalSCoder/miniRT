/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_mult_v3.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 15:36:57 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:18:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_vector3	quat_mult_v3(t_vector3 vect, t_quat quat_in)
{
	t_quat	p;
	t_quat	q;

	p.s = 0;
	p.vect = vect;
	q = quat_mult(quat_in, p);
	q = quat_mult(q, quat_inverse(quat_in));
	return (q.vect);
}
