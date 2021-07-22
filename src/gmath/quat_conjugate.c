/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_conjugate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:58:21 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:18:14 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_quat	quat_conjugate(t_quat q1)
{
	q1.vect = v3_multiply(q1.vect, -1);
	return (q1);
}
