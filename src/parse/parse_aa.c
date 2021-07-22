/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_aa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 18:20:52 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/22 17:02:50 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_aa(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 1)
		return (err_splitcount);
	if (parse_uchar(*strs, &scene->aalias.samplec) != err_success)
		return (err_param);
	return (err_success);
}
