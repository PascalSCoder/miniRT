/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rad_to_deg.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:24:12 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/23 12:42:20 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns radians converted to degrees.
*/
double	rad_to_deg(double rad)
{
	return (rad * (180 / M_PI));
}
