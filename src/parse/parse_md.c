/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_md.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 13:20:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 13:21:27 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_md(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 1)
		return (err_splitcount);
	if (parse_uchar(*strs, &scene->max_depth) != err_success)
		return (err_param);
	return (err_success);
}
