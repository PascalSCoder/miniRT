/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_transform_m4.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:52:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 15:56:46 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns a vector result of vect multiplied by mtrx.
*/
t_vector3	v3_transform_m4(t_vector3 vect, t_matrix4 mtrx)
{
	t_vector3	vect_b;
	double		tmp[4];
	int			i;

	i = 0;
	while (i < 4)
	{
		tmp[i] = vect.x * mtrx.map[0][i]
			+ vect.y * mtrx.map[1][i]
			+ vect.z * mtrx.map[2][i]
			+ mtrx.map[3][i];
		i++;
	}
	vect_b.x = tmp[0] / tmp[3];
	vect_b.y = tmp[1] / tmp[3];
	vect_b.z = tmp[2] / tmp[3];
	return (vect_b);
}
