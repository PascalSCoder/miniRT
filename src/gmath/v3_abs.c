/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_abs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:01:25 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:17:01 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns an absolute duplicate of vect.
*/
t_vector3	v3_abs(t_vector3 vect)
{
	if (vect.x < 0)
		vect.x *= -1;
	if (vect.y < 0)
		vect.y *= -1;
	if (vect.z < 0)
		vect.z *= -1;
	return (vect);
}
