/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_t.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 18:15:37 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:48:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_t(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 1)
		return (err_splitcount);
	if (parse_uchar(*strs, &scene->threadc) != err_success)
		return (err_param);
	if (scene->threadc == 0)
		return (err_param);
	return (err_success);
}
