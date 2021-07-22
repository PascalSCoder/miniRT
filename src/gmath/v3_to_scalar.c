/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_to_scalar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:03:14 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:13:31 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns a scalar of vect. (i.e. coordinates combined)
*/
double	v3_to_scalar(t_vector3 vect)
{
	return (vect.x + vect.y + vect.z);
}
