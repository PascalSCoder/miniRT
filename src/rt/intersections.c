/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersections.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/17 10:59:18 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:23:24 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/rt.h"

/*
**	Returns 0 if t_obj_type of obj does not exist.
**	Otherwise returns intersection test result.
*/
char	intersections(t_vector3 origin, t_vector3 dir, void *obj, double *t)
{
	char		(*isf)(t_vector3, t_vector3, void*, double*);
	t_obj_type	type;

	type = *(t_obj_type *)obj;
	if (type < 0 || type > 4)
		return (0);
	isf = get_intersectf(type);
	return (isf(origin, dir, obj, t));
}
