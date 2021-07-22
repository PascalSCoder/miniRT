/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v3_isgreater.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:07:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:14:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns whether vect_a > vect_b.
*/
char	v3_isgreater(t_vector3 vect_a, t_vector3 vect_b)
{
	if (v3_to_scalar(vect_a) > v3_to_scalar(vect_b))
		return (1);
	return (0);
}
