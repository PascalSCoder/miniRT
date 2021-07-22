/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m3_set.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:47:20 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 14:03:54 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns a t_matrix3 from vectors x, y and z.
*/
t_matrix3	m3_set(t_vector3 x, t_vector3 y, t_vector3 z)
{
	return ((t_matrix3){.x = x, .y = y, .z = z});
}
