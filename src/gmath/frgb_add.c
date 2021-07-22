/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frgb_add.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:25:36 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/23 13:51:40 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_frgb	frgb_add(t_frgb rgb1, t_frgb rgb2)
{
	rgb1.r += rgb2.r;
	rgb1.g += rgb2.g;
	rgb1.b += rgb2.b;
	return (rgb1);
}
