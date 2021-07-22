/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_reflect.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 15:19:30 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 11:01:13 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

// 𝑟 = 𝑑 − 2(𝑑⋅𝑛)𝑛

t_vector3	v3_reflect(t_vector3 in, t_vector3 n)
{
	return (v3_subtract(in, v3_multiply(n, v3_dot(in, n) * 2)));
}
