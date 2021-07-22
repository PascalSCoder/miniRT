/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m3_from_orient.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 14:05:54 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 14:06:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_matrix3	m3_from_orient(t_vector3 orient)
{
	t_matrix3	m;

	m.z = orient;
	m.x = v3_cross(v3_new(0, 1, 0), orient);
	if (v3_magnitude(m.y) == 0)
		m.y = v3_new(1, 0, 0);
	m.y = v3_cross(m.x, m.z);
	return (m);
}
