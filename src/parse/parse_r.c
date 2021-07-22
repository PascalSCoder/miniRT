/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_r.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:41:34 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_r(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 2)
		return (err_splitcount);
	if (parse_int(*strs, &scene->res.width) != err_success)
		return (err_param);
	strs++;
	if (parse_int(*strs, &scene->res.height) != err_success)
		return (err_param);
	if (scene->res.width <= 0 || scene->res.height <= 0)
		return (err_param);
	return (err_success);
}
