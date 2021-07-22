/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frgb_mult_frgb.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:27:47 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/23 14:13:12 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_frgb	frgb_mult_frgb(t_frgb rgb1, t_frgb rgb2)
{
	rgb1.r = rgb1.r * rgb2.r / 255;
	rgb1.g = rgb1.g * rgb2.g / 255;
	rgb1.b = rgb1.b * rgb2.b / 255;
	return (rgb1);
}
