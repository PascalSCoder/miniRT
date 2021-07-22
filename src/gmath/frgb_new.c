/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frgb_zero.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/23 14:07:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/23 14:08:31 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_frgb	frgb_new(float r, float g, float b)
{
	return ((t_frgb){.r = r, .g = g, .b = b});
}
