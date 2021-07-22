/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m4_add.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:51:15 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 14:11:48 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns C = A + B.
*/
t_matrix4	m4_add(t_matrix4 a, t_matrix4 b)
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
			c.map[i][j] = a.map[i][j] + b.map[i][j];
			j++;
		}
		i++;
	}
	return (c);
}
