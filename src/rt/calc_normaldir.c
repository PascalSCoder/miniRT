/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_normaldir.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/26 15:20:30 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/26 15:21:32 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

t_vector3	calc_normaldir(t_vector3 n, t_vector3 dir)
{
	if (v3_dot(n, dir) <= 0)
		return (n);
	else
		return (v3_multiply(n, -1));
}
