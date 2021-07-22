/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_move.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 00:32:09 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/26 00:32:32 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_vector3	v3_move(t_vector3 forward, t_vector3 pos, t_vector3 move)
{
	return (v3_transform_m4(move, m4_from_orient(forward, pos)));
}
