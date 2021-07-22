/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cam_control.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/26 12:42:38 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:43:49 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/errors.h"
#include "../../public/datatypes.h"

t_camera	*get_next_camera(t_list *cameras)
{
	static t_list	*active_cam;

	if (!cameras)
		program_exit(err_success, "There are no cameras defined.");
	if (!active_cam || !active_cam->next)
		active_cam = cameras;
	else
		active_cam = active_cam->next;
	return (active_cam->element);
}
