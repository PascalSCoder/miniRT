/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_image.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/03 14:25:11 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/14 11:54:07 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/mlx.h"
#include "../public/libft.h"
#include "../public/errors.h"
#include "../public/datatypes.h"
#include <stdlib.h>

void	put_pixels(t_res res, t_image *image, t_rgb *frame)
{
	char	*addr;
	int		x;
	int		y;

	y = 0;
	while (y < res.height)
	{
		x = 0;
		while (x < res.width)
		{
			addr = image->data_addr + (y * image->size_line) + x * (image->bpp);
			addr[0] = frame[y * res.width + x].b;
			addr[1] = frame[y * res.width + x].g;
			addr[2] = frame[y * res.width + x].r;
			x++;
		}
		y++;
	}
}

void	display_image(t_scene *scene, t_rgb *frame)
{
	t_image	image;

	if (scene->active_frame)
		free(scene->active_frame);
	scene->active_frame = frame;
	image.image = mlx_new_image(scene->mlxdata->mlx,
			scene->res.width, scene->res.height);
	if (!image.image)
		program_exit(err_system, 0);
	image.data_addr = mlx_get_data_addr(image.image,
			&image.bpp,
			&image.size_line,
			&image.endian);
	image.bpp /= 8;
	put_pixels(scene->res, &image, frame);
	mlx_put_image_to_window(scene->mlxdata->mlx, scene->mlxdata->window,
		image.image, 0, 0);
	mlx_destroy_image(scene->mlxdata->mlx, image.image);
}
