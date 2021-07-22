/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frgb_mult.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:27:16 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/23 14:10:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_frgb	frgb_mult(t_frgb rgb, float f)
{
	rgb.r *= f;
	rgb.g *= f;
	rgb.b *= f;
	return (rgb);
}
