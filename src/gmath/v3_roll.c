/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_roll.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 14:04:54 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 14:09:59 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"
#include <math.h>

void	v3_roll(double angle, t_vector3 *vect)
{
	t_matrix4	m;
	double		s;
	double		c;

	angle = deg_to_rad(angle);
	c = cos(angle);
	s = sin(angle);
	m = m4_from_orient(*vect, v3_new(0, 0, 0));
	*vect = v3_normalize(v3_transform_m4(v3_new(s, c, 0), m));
}
