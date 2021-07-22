/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_isequal.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:08:00 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:15:39 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"
#include "../../public/libft.h"

char	v3_isequal(t_vector3 vect_a, t_vector3 vect_b)
{
	if (!ft_memcmp(&vect_a, &vect_b, sizeof(t_vector3)))
		return (1);
	return (0);
}
