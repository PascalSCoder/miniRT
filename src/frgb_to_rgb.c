/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frgb_to_rgb.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 13:42:39 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:01:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/datatypes.h"
#include "../public/errors.h"
#include "../public/debug.h"
#include <stdlib.h>

static unsigned char	float_to_uchar(float n)
{
	if (n < 0)
		n = 0;
	else if (n > 255)
		n = 255;
	return ((unsigned char)n);
}

t_rgb	*frgb_to_rgb(t_frgb *frame, t_res res)
{
	unsigned int	size;
	unsigned int	i;
	t_rgb			*dest;

	size = res.height * res.width;
	dest = malloc(size * sizeof(t_rgb));
	if (!dest)
		program_exit(err_system, 0);
	i = 0;
	while (i < size)
	{
		dest[i].r = float_to_uchar(frame[i].r);
		dest[i].g = float_to_uchar(frame[i].g);
		dest[i].b = float_to_uchar(frame[i].b);
		dest[i].a = 0;
		i++;
	}
	free(frame);
	return (dest);
}
