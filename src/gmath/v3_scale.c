/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_scale.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:02:13 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:13:46 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the scaled value (multiply a by b) of 2 vectors.
*/
t_vector3	v3_scale(t_vector3 vect_a, t_vector3 vect_b)
{
	vect_a.x *= vect_b.x;
	vect_a.y *= vect_b.y;
	vect_a.z *= vect_b.z;
	return (vect_a);
}
