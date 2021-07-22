/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_scene.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 17:28:01 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:36:04 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/datatypes.h"
#include "../public/rt.h"
#include <math.h>
#include <stdlib.h>

static double	get_focal(unsigned char fov, int width)
{
	return ((width / 2) / tan(deg_to_rad(fov / 2)));
}

static void	set_cam_focal(t_scene *scene, t_list *cameras)
{
	t_camera	*cam;

	if (cameras->next)
		set_cam_focal(scene, cameras->next);
	cam = (t_camera *)cameras->element;
	cam->focal_len = get_focal(cam->fov, scene->res.width);
}

static t_vector2	*init_subdiv_table(int division)
{
	int			v;
	int			h;
	t_vector2	*table;

	table = malloc(division * division * sizeof(t_vector2));
	if (!table)
		program_exit(err_system, 0);
	v = 0;
	while (v < division)
	{
		h = 0;
		while (h < division)
		{
			table[(v * h) + h].y = (double)v / (division - 1);
			table[(v * h) + h].x = (double)h / (division - 1);
			h++;
		}
		v++;
	}
	return (table);
}

void	init_scene(t_scene *scene)
{
	set_cam_focal(scene, scene->cameras);
	scene->active_cam = get_next_camera(scene->cameras);
	if (scene->threadc == 0)
		scene->threadc = 1;
	if (scene->aalias.samplec == 0)
		scene->aalias.samplec = 1;
	scene->aalias.subdivc = sqrt(scene->aalias.samplec);
	scene->aalias.subdiv_table = init_subdiv_table(scene->aalias.subdivc);
}
