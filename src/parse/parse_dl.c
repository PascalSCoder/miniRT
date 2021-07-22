/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_dl.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 22:48:51 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:30:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

static t_err	set_values(t_dirlight *light, char **strs)
{
	if (parse_vector3(*strs, &light->dir) != err_success)
		return (err_param);
	light->dir = v3_normalize(light->dir);
	strs++;
	if (parse_double(*strs, &light->luminosity) != err_success)
		return (err_param);
	if (!isclamped(light->luminosity, 0, 1))
		return (err_param);
	strs++;
	if (parse_rgb(*strs, &light->rgb) != err_success)
		return (err_param);
	return (err_success);
}

t_err	parse_dl(t_scene *scene, char **strs)
{
	t_dirlight	*light;

	if (strs_count(strs) != 3)
		return (err_splitcount);
	light = ft_calloc(1, sizeof(t_dirlight));
	if (!light)
		return (err_system);
	light->type = lt_dir;
	if (lst_addnewback(&scene->lightsrcs, (void *)light))
		return (set_values(light, strs));
	free(light);
	return (err_system);
}
