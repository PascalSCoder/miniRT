/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quat_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 12:16:27 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:17:49 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_quat	quat_new(t_vector3 vect, double s)
{
	return (quat_unit_normalize((t_quat){.s = s, .vect = vect}));
}
