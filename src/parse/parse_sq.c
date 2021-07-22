/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sq.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:41:43 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

static void	set_adj(t_square *sq)
{
	t_matrix4	m4;

	m4 = m4_from_orient(sq->orientation, sq->position);
	sq->adjdir = v3_normalize(v3_transform_m4(v3_new(sq->size, 0, 0), m4));
}

static t_err	set_values(t_square *square, char **strs)
{
	if (parse_vector3(*strs, &square->position) != err_success)
		return (err_param);
	strs++;
	if (parse_vector3(*strs, &square->orientation) != err_success)
		return (err_param);
	square->orientation = v3_normalize(square->orientation);
	strs++;
	if (parse_int(*strs, &square->size) != err_success)
		return (err_param);
	if (square->size < 0)
		return (err_param);
	strs++;
	if (parse_rgb(*strs, &square->rgb) != err_success)
		return (err_param);
	strs++;
	if (*strs)
		if (parse_physmat(*strs, &square->physmat) != err_success)
			return (err_param);
	set_adj(square);
	return (err_success);
}

t_err	parse_sq(t_scene *scene, char **strs)
{
	t_square	*square;

	if (strs_count(strs) != 4 && strs_count(strs) != 5)
		return (err_splitcount);
	square = ft_calloc(1, sizeof(t_square));
	if (!square)
		return (err_system);
	square->obj = obj_square;
	if (lst_addnewback(&scene->objects, (void *)square))
		return (set_values(square, strs));
	free(square);
	return (err_system);
}
