/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_sp.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:43:39 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

static t_err	set_values(t_sphere *sphere, char **strs)
{
	if (parse_vector3(*strs, &sphere->position) != err_success)
		return (err_param);
	strs++;
	if (parse_double(*strs, &sphere->diameter2) != err_success)
		return (err_param);
	if (sphere->diameter2 <= 0)
		return (err_param);
	strs++;
	if (parse_rgb(*strs, &sphere->rgb) != err_success)
		return (err_param);
	strs++;
	if (*strs)
		if (parse_physmat(*strs, &sphere->physmat) != err_success)
			return (err_param);
	sphere->diameter2 = (sphere->diameter2 / 2) * (sphere->diameter2 / 2);
	return (err_success);
}

t_err	parse_sp(t_scene *scene, char **strs)
{
	t_sphere	*sphere;

	if (strs_count(strs) != 3 && strs_count(strs) != 4)
		return (err_splitcount);
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (err_system);
	sphere->obj = obj_sphere;
	if (lst_addnewback(&scene->objects, (void *)sphere))
		return (set_values(sphere, strs));
	free(sphere);
	return (err_system);
}
