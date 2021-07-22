/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   m4_set.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:47:55 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:18:19 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns a t_matrix4 from the euler angles of origin
*/
t_matrix4	m4_set(t_vector3 rt, t_vector3 up, t_vector3 fw, t_vector3 o)
{
	t_matrix4	mtrx;

	mtrx.map[0][0] = rt.x;
	mtrx.map[0][1] = rt.y;
	mtrx.map[0][2] = rt.z;
	mtrx.map[0][3] = 0;
	mtrx.map[1][0] = up.x;
	mtrx.map[1][1] = up.y;
	mtrx.map[1][2] = up.z;
	mtrx.map[1][3] = 0;
	mtrx.map[2][0] = fw.x;
	mtrx.map[2][1] = fw.y;
	mtrx.map[2][2] = fw.z;
	mtrx.map[2][3] = 0;
	mtrx.map[3][0] = o.x;
	mtrx.map[3][1] = o.y;
	mtrx.map[3][2] = o.z;
	mtrx.map[3][3] = 1;
	return (mtrx);
}
