/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 12:35:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:41:12 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include <stdlib.h>

t_err	parse_c(t_scene *scene, char **strs)
{
	t_camera	*cam;

	if (strs_count(strs) != 3)
		return (err_splitcount);
	cam = (t_camera *)ft_calloc(1, sizeof(t_camera));
	if (!cam)
		return (err_system);
	if (!lst_addnewback(&scene->cameras, (void *)cam))
	{
		free(cam);
		return (err_system);
	}
	if (parse_vector3(*strs, &cam->position) != err_success)
		return (err_param);
	strs++;
	if (parse_vector3(*strs, &cam->orientation) != err_success)
		return (err_param);
	cam->orientation = v3_normalize(cam->orientation);
	strs++;
	if (parse_uchar(*strs, &cam->fov) != err_success)
		return (err_param);
	if (cam->fov == 0)
		return (err_param);
	return (err_success);
}
