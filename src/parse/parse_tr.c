/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/01 18:31:53 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

#include "../../public/debug.h"

static t_err	set_values(t_triangle *triangle, char **strs)
{
	if (parse_vector3(*strs, &triangle->p0) != err_success)
		return (err_param);
	strs++;
	if (parse_vector3(*strs, &triangle->p1) != err_success)
		return (err_param);
	strs++;
	if (parse_vector3(*strs, &triangle->p2) != err_success)
		return (err_param);
	strs++;
	if (parse_rgb(*strs, &triangle->rgb) != err_success)
		return (err_param);
	return (err_success);
}

t_err	parse_tr(t_scene *scene, char **strs)
{
	t_triangle	*triangle;

	if (strs_count(strs) != 4)
		return (err_splitcount);
	triangle = ft_calloc(1, sizeof(t_triangle));
	if (!triangle)
		return (err_system);
	triangle->obj = obj_triangle;
	if (lst_addnewback(&scene->objects, (void *)triangle))
		return (set_values(triangle, strs));
	free(triangle);
	return (err_system);
}
