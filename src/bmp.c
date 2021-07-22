/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bmp.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 13:42:34 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/12 14:09:55 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/errors.h"
#include "../public/datatypes.h"
#include "../public/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static char	bmp_write_header(int fd, int pixels)
{
	int	tmp;
	int	written;

	written = 0;
	written += write(fd, "BM", 2);
	tmp = (pixels * 4) + 14 + 40;
	written += write(fd, &tmp, 4);
	tmp = 0;
	written += write(fd, &tmp, 2);
	written += write(fd, &tmp, 2);
	tmp = 54;
	written += write(fd, &tmp, 4);
	if (written != 14)
		return (0);
	return (1);
}

static char	bmp_write_info(int fd, int width, int height)
{
	int	tmp;
	int	written;

	written = 0;
	tmp = 40;
	written += write(fd, &tmp, 4);
	written += write(fd, &width, 4);
	written += write(fd, &height, 4);
	tmp = 1;
	written += write(fd, &tmp, 2);
	tmp = 32;
	written += write(fd, &tmp, 2);
	tmp = 0;
	written += write(fd, &tmp, 4);
	written += write(fd, &tmp, 4);
	written += write(fd, &tmp, 4);
	written += write(fd, &tmp, 4);
	written += write(fd, &tmp, 4);
	written += write(fd, &tmp, 4);
	if (written != 40)
		return (0);
	return (1);
}

static char	bmp_write_bitmap(int fd, t_rgb *bitmap, int pixels)
{
	ssize_t	written;

	written = write(fd, bitmap, pixels * 4);
	free(bitmap);
	if (written != pixels * 4)
		return (0);
	return (1);
}

static t_rgb	*parse_bitmap(t_rgb *rgbmap, int x, int y)
{
	t_rgb	*bitmap;
	int		i;
	int		j;
	int		pixel;
	int		bytepos;

	bitmap = ft_calloc(x * y, sizeof(t_rgb));
	if (!bitmap)
		program_exit(err_system, 0);
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			pixel = (y - j - 1) * x + i;
			bytepos = (j * x) + i;
			bitmap[bytepos].b = rgbmap[pixel].b;
			bitmap[bytepos].g = rgbmap[pixel].g;
			bitmap[bytepos].r = rgbmap[pixel].r;
			i++;
		}
		j++;
	}
	return (bitmap);
}

void	initstate_bmp(t_rgb *frame, t_res res)
{
	int		fd;
	t_rgb	*bitmap;
	int		pixels;

	fd = open("minirt.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		program_exit(err_system, "Failed to create file minirt.bmp.");
	pixels = res.width * res.height;
	bmp_write_header(fd, pixels);
	bmp_write_info(fd, res.width, res.height);
	bitmap = parse_bitmap(frame, res.width, res.height);
	if (bmp_write_bitmap(fd, bitmap, pixels))
		printf("Saved minirt.bmp\n");
	else
		program_exit(err_system, "Occured while saving minirt.bmp.");
	close(fd);
}
