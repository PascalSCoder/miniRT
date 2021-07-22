/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_bg.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 23:57:02 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:57:32 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_bg(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 1)
		return (err_splitcount);
	if (parse_rgb(*strs, &scene->bg_color) != err_success)
		return (err_param);
	return (err_success);
}
