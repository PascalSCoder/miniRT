/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threading.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 22:43:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/31 19:47:51 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/rt.h"

void	create_threads(t_scene *scene, t_frgb *frame)
{
	scene->threadc = 1;
	render_thread(&(t_thread){.frame = frame, .id = 0, .scene = scene});
}
