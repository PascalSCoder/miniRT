/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_inverse.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:58:38 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:18:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_quat	quat_inverse(t_quat q1)
{
	double	magn;

	magn = quat_magnitude(q1);
	magn = 1 / (magn * magn);
	q1 = quat_conjugate(q1);
	q1.s = q1.s * magn;
	q1.vect = v3_multiply(q1.vect, magn);
	return (q1);
}
