/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_divide.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:05:16 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:16:27 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns vect divided by n.
*/
t_vector3	v3_divide(t_vector3 vect, double n)
{
	vect.x /= n;
	vect.y /= n;
	vect.z /= n;
	return (vect);
}
