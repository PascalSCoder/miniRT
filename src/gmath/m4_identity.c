/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m4_identity.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 12:08:59 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 14:12:20 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns the identity matrix.
*/
t_matrix4	m4_identity(void)
{
	t_matrix4	mtrx;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mtrx.map[i][j] = 1;
			else
				mtrx.map[i][j] = 0;
			j++;
		}
		i ++;
	}
	return (mtrx);
}
