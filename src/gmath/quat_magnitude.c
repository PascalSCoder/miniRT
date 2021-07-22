/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_magnitude.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:56:38 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:22:41 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"
#include <math.h>

/*
**	Returns the scalar magnitude of q1.
*/
double	quat_magnitude(t_quat q1)
{
	return (sqrt(q1.s * q1.s + v3_to_scalar(q1.vect) * v3_to_scalar(q1.vect)));
}
