/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_l.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:41:21 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

static t_err	set_values(t_spotlight *light, char **strs)
{
	if (parse_vector3(*strs, &light->position) != err_success)
		return (err_param);
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

t_err	parse_l(t_scene *scene, char **strs)
{
	t_spotlight	*light;

	if (strs_count(strs) != 3)
		return (err_splitcount);
	light = ft_calloc(1, sizeof(t_spotlight));
	if (!light)
		return (err_system);
	light->type = lt_spot;
	if (lst_addnewback(&scene->lightsrcs, (void *)light))
		return (set_values(light, strs));
	free(light);
	return (err_system);
}
