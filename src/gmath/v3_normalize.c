/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_normalize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:02:45 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:14:18 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns argument vect normalized.
**	v = v / |v|
*/
t_vector3	v3_normalize(t_vector3 vect)
{
	if (v3_isequal(vect, v3_new(0, 0, 0)))
		return (vect);
	return (v3_divide(vect, v3_magnitude(vect)));
}
