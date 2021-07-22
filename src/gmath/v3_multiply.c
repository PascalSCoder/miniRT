/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_multiply.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:04:52 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:14:32 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns vect multiplied by n.
*/
t_vector3	v3_multiply(t_vector3 vect, double n)
{
	vect.x *= n;
	vect.y *= n;
	vect.z *= n;
	return (vect);
}
