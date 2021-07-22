/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_obj_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 16:10:24 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:24:51 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

t_vector3	get_obj_normal(t_obj_type type, t_ray *ray)
{
	t_vector3	(*f)(t_ray *);

	f = get_normalf(type);
	if (f)
		return (f(ray));
	return ((t_vector3){.x = 0, .y = 0, .z = 0});
}

t_frgb	get_obj_color(void *obj)
{
	obj += sizeof(t_obj_type);
	return (*(t_frgb *)obj);
}

t_vector3	get_obj_position(void *obj)
{
	obj += sizeof(t_obj_type) + sizeof(t_frgb) + sizeof(t_physmat *);
	return (*(t_vector3 *)obj);
}

t_obj_type	get_obj_type(void *obj)
{
	return (*(t_obj_type *)obj);
}

t_physmat	*get_obj_physmat(void *obj)
{
	return (((t_sphere *)obj)->physmat);
}
