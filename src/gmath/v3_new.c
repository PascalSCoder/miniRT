/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_new.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:07:14 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:14:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns a t_vector3 with doubles x, y, z values.
*/
t_vector3	v3_new(double x, double y, double z)
{
	return ((t_vector3){.x = x, .y = y, .z = z});
}
