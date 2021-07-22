/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enable_debug.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/03 15:09:15 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/03 15:17:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	enable_debug(t_scene *scene, char **strs)
{
	if (strs_count(strs) != 0)
		return (err_splitcount);
	scene->debug = 1;
	return (err_success);
}
