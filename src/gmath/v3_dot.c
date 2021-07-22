/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_dot.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:05:45 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 15:56:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the dot product of vect_a and vect_b
**	The dot product represents vect_a projected onto vect_b
*/
double	v3_dot(t_vector3 va, t_vector3 vb)
{
	return ((va.x * vb.x) + (va.y * vb.y) + (va.z * vb.z));
}
