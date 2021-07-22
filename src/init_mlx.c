/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/03 14:16:58 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/10 12:50:35 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/datatypes.h"
#include "../public/mlx.h"
#include "../public/events.h"
#include "../public/errors.h"
#include "../public/libft.h"

static void	set_resolution(void *mlx, t_res *res)
{
	int		xsize;
	int		ysize;
	float	aspectratio;

	mlx_get_screen_size(mlx, &xsize, &ysize);
	aspectratio = (float)res->width / res->height;
	if (res->width > xsize)
	{
		res->width = xsize;
		res->height = res->width / aspectratio;
	}
	if (res->height > ysize)
	{
		res->height = ysize;
		res->width = res->height * aspectratio;
	}
}

void	init_mlx(t_scene *scene)
{
	scene->mlxdata = ft_calloc(1, sizeof(t_mlxdata));
	if (!scene->mlxdata)
		program_exit(err_system, 0);
	scene->mlxdata->mlx = mlx_init();
	if (!scene->mlxdata->mlx)
		program_exit(err_system, 0);
	set_resolution(scene->mlxdata->mlx, &scene->res);
}
