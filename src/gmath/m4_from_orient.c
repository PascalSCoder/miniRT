/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m4_from_orient.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:48:44 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/19 13:55:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_matrix4	m4_from_orient(t_vector3 orient, t_vector3 origin)
{
	t_matrix4	m;

	m.forward = orient;
	m.right = v3_cross(v3_new(0, 1, 0), orient);
	if (v3_magnitude(m.right) == 0)
		m.right = v3_new(1, 0, 0);
	m.up = v3_cross(m.forward, m.right);
	m.origin = origin;
	m.x = 0;
	m.y = 0;
	m.z = 0;
	m.w = 1;
	return (m);
}
