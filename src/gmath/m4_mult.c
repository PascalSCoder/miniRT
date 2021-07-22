/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m4_mult.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:50:44 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 15:46:41 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns C = A * B.
*/
t_matrix4	m4_mult(t_matrix4 a, t_matrix4 b)
{
	t_matrix4	c;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c.map[i][j] = a.map[i][0] * b.map[0][j]
				+ a.map[i][1] * b.map[1][j]
				+ a.map[i][2] * b.map[2][j]
				+ a.map[i][3] * b.map[3][j];
			j++;
		}
		i++;
	}
	return (c);
}
