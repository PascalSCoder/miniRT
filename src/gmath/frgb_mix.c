/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frgb_mix.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:00:19 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/26 18:01:15 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"
#include <stdlib.h>

t_frgb	frgb_mix(t_frgb *colors, int n)
{
	int		i;
	t_frgb	new;

	i = 0;
	new = frgb_new(0, 0, 0);
	while (i < n)
	{
		new.r += colors[i].r / n;
		new.g += colors[i].g / n;
		new.b += colors[i].b / n;
		i++;
	}
	free(colors);
	return (new);
}
