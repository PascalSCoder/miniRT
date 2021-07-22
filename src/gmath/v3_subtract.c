/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_subtract.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:05:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:13:41 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns vect_a subtracted by vect_b.
*/
t_vector3	v3_subtract(t_vector3 vect_a, t_vector3 vect_b)
{
	vect_a.x -= vect_b.x;
	vect_a.y -= vect_b.y;
	vect_a.z -= vect_b.z;
	return (vect_a);
}
