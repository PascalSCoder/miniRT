/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_add.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:08:38 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:16:57 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns vect_b added to vect_a.
*/
t_vector3	v3_add(t_vector3 vect_a, t_vector3 vect_b)
{
	vect_a.x += vect_b.x;
	vect_a.y += vect_b.y;
	vect_a.z += vect_b.z;
	return (vect_a);
}
