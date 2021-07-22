/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m3_mult.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 14:06:25 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 14:06:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_matrix3	m3_mult(t_matrix3 a, t_matrix3 b)
{
	t_matrix3	c;
	int			i;
	int			j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			c.map[i][j] = a.map[i][0] * b.map[0][j]
				+ a.map[i][1] * b.map[1][j]
				+ a.map[i][2] * b.map[2][j];
			j++;
		}
		i++;
	}
	return (c);
}
