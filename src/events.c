/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/23 12:40:22 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 14:24:51 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/events.h"
#include "../public/state.h"
#include "../public/rt.h"
#include "../public/debug.h"
#include <unistd.h>
#include <math.h>

static void	cam_move(t_vector3 moveto, t_camera *cam)
{
	cam->position = v3_move(cam->orientation, cam->position, moveto);
}

static char	check_inputs(t_scene *scene, int keycode)
{
	if (keycode == KEY_NEXTCAM)
		scene->active_cam = get_next_camera(scene->cameras);
	else if (keycode == KEY_A)
		cam_move(v3_new(-10, 0, 0), scene->active_cam);
	else if (keycode == KEY_D)
		cam_move(v3_new(10, 0, 0), scene->active_cam);
	else if (keycode == KEY_W)
		cam_move(v3_new(0, 0, 10), scene->active_cam);
	else if (keycode == KEY_S)
		cam_move(v3_new(0, 0, -10), scene->active_cam);
	else if (keycode == KEY_Z)
		cam_move(v3_new(0, 10, 0), scene->active_cam);
	else if (keycode == KEY_X)
		cam_move(v3_new(0, -10, 0), scene->active_cam);
	else if (keycode == KEY_Q)
		v3_yaw(-15, &scene->active_cam->orientation);
	else if (keycode == KEY_E)
		v3_yaw(15, &scene->active_cam->orientation);
	else if (keycode == KEY_R)
		v3_pitch(15, &scene->active_cam->orientation);
	else if (keycode == KEY_F)
		v3_pitch(-15, &scene->active_cam->orientation);
	else
		return (0);
	return (1);
}

static char	check_cam_input(t_scene *scene, int keycode)
{
	t_rgb	*frame;

	if (check_inputs(scene, keycode))
	{
		if (scene->debug)
		{
			printf("Camera:\n");
			printv3(scene->active_cam->position, "Position");
			printv3(scene->active_cam->orientation, "Orientation");
		}
		write(0, "Rendering new image...", 22);
		frame = frgb_to_rgb(initstate_render(scene), scene->res);
		display_image(scene, frame);
		write(0, " Finished!\n", 11);
		return (1);
	}
	return (0);
}

int	key_pressed(int keycode, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keycode == KEY_CLOSE)
		program_exit(err_success, "Terminating program by escape event.");
	else if (keycode == KEY_BMP)
		initstate_bmp(scene->active_frame, scene->res);
	else
		check_cam_input(scene, keycode);
	return (0);
}
