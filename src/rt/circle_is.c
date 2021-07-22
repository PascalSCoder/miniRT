/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   circle_is.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 16:26:28 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 16:27:16 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

char	circle_is(t_vector3 origin, t_vector3 dir, t_circle *circle, double *t)
{
	if (plane_is(origin, dir, &circle->pl, t))
		if (v3_magnitude(v3_subtract(v3_add(origin, v3_multiply(dir, *t)),
					circle->pl.position)) <= circle->r)
			return (1);
	return (0);
}
