/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_magnitude.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 10:38:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:15:14 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"
#include <math.h>

/*
**	Returns the magnitude of vect.
*/
double	v3_magnitude(t_vector3 vect)
{
	vect = v3_abs(vect);
	return (sqrt(pow(vect.x, 2) + pow(vect.y, 2) + pow(vect.z, 2)));
}
