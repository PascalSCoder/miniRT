/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   obj_distr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 11:29:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 16:15:34 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

void	*get_intersectf(t_obj_type type)
{
	const void	*ftable[] = {
		sphere_is,
		plane_is,
		square_is,
		cylinder_is,
		triangle_is
	};

	return ((void *)ftable[type]);
}

void	*get_normalf(t_obj_type type)
{
	const void	*ftable[] = {
		sphere_normal,
		plane_normal,
		square_normal,
		cylinder_normal,
		triangle_normal
	};

	return ((void *)ftable[type]);
}
