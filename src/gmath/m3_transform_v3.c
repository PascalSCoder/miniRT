/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m3_transform_v3.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/05 13:10:13 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/05 13:12:43 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns a vector result of vect multiplied by mtrx.
*/
t_vector3	m3_transform_v3(t_matrix3 mtrx, t_vector3 vect)
{
	double		tmp[3];
	int			i;

	i = 0;
	while (i < 3)
	{
		tmp[i] = vect.x * mtrx.map[0][i]
			+ vect.y * mtrx.map[1][i]
			+ vect.z * mtrx.map[2][i];
		i++;
	}
	vect.x = tmp[0];
	vect.y = tmp[1];
	vect.z = tmp[2];
	return (vect);
}
