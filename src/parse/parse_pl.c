/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_pl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:41:30 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

static t_err	set_values(t_plane *plane, char **strs)
{
	if (parse_vector3(*strs, &plane->position) != err_success)
		return (err_param);
	strs++;
	if (parse_vector3(*strs, &plane->orientation) != err_success)
		return (err_param);
	plane->orientation = v3_normalize(plane->orientation);
	strs++;
	if (parse_rgb(*strs, &plane->rgb) != err_success)
		return (err_param);
	strs++;
	if (*strs)
		if (parse_physmat(*strs, &plane->physmat) != err_success)
			return (err_param);
	return (err_success);
}

t_err	parse_pl(t_scene *scene, char **strs)
{
	t_plane	*plane;

	if (strs_count(strs) != 3 && strs_count(strs) != 4)
		return (err_splitcount);
	plane = ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (err_system);
	plane->obj = obj_plane;
	if (lst_addnewback(&scene->objects, (void *)plane))
		return (set_values(plane, strs));
	free(plane);
	return (err_system);
}
