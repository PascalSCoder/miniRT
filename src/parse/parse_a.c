/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:40:00 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_a(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 2)
		return (err_splitcount);
	if (parse_double(*strs, &scene->ambient.luminosity) != err_success)
		return (err_param);
	if (!isclamped(scene->ambient.luminosity, 0, 1))
		return (err_param);
	strs++;
	if (parse_rgb(*strs, &scene->ambient.rgb) != err_success)
		return (err_param);
	return (err_success);
}
