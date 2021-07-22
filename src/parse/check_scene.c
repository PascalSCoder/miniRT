/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_scene.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 15:46:25 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:52:57 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/errors.h"
#include "../../public/datatypes.h"

void	check_scene(t_scene *scene)
{
	if (scene->res.height <= 0 || scene->res.width <= 0)
		program_exit(err_param, "The scene resolution is not set correctly.");
	if (!scene->cameras)
		program_exit(err_param, "There are no cameras configured.");
}
