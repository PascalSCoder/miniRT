/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_cy.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:41:17 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

static	t_err	set_values(t_cylinder *cy, char **strs)
{
	if (parse_vector3(*strs, &cy->position) != err_success)
		return (err_param);
	strs++;
	if (parse_vector3(*strs, &cy->orientation) != err_success)
		return (err_param);
	cy->orientation = v3_normalize(cy->orientation);
	strs++;
	if (parse_double(*strs, &cy->diameter) != err_success)
		return (err_param);
	cy->diameter = cy->diameter / 2;
	strs++;
	if (parse_double(*strs, &cy->height) != err_success)
		return (err_param);
	cy->height = cy->height / 2;
	strs++;
	if (parse_rgb(*strs, &cy->rgb) != err_success)
		return (err_param);
	if (cy->diameter < 0 || cy->height < 0)
		return (err_param);
	return (err_success);
}

t_err	parse_cy(t_scene *scene, char **strs)
{
	t_cylinder	*cy;

	if (strs_count(strs) != 5)
		return (err_splitcount);
	cy = ft_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (err_system);
	cy->obj = obj_cylinder;
	if (lst_addnewback(&scene->objects, (void *)cy))
		return (set_values(cy, strs));
	free(cy);
	return (err_system);
}
