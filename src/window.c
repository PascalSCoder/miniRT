/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/10 13:58:18 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/03 14:58:51 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/mlx.h"
#include "../public/rt.h"
#include "../public/events.h"

static int	close_mlx(void *param)
{
	program_exit(0, (char *)param);
	return (0);
}

void	initstate_mlx(t_rgb *frame, t_scene *scene)
{
	scene->mlxdata->window = mlx_new_window(scene->mlxdata->mlx,
			scene->res.width, scene->res.height, "MiniRT");
	if (!scene->mlxdata->window)
		program_exit(err_system, 0);
	mlx_key_hook(scene->mlxdata->window, key_pressed, scene);
	mlx_mouse_hook(scene->mlxdata->window, mb_pressed, scene);
	mlx_hook(scene->mlxdata->window, KEY_CROSS, 0L, close_mlx, 0);
	display_image(scene, frame);
	mlx_loop(scene->mlxdata->mlx);
}
