/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_cross.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 15:35:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/18 21:21:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the cross product of 2 vectors.
*/
t_vector3	v3_cross(t_vector3 a, t_vector3 b)
{
	t_vector3	cross;

	cross.x = (a.y * b.z) - (a.z * b.y);
	cross.y = -((a.x * b.z) - a.z * b.x);
	cross.z = (a.x * b.y) - (a.y * b.x);
	return (cross);
}
