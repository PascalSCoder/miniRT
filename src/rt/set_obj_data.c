/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_obj_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 12:38:09 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:26:41 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

void	set_obj_color(void *obj, t_frgb rgb)
{
	obj += sizeof(t_obj_type);
	*(t_frgb *)obj = rgb;
}
