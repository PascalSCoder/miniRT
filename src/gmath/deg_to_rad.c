/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   deg_to_rad.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 15:32:47 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/23 12:41:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/gmath.h"

/*
**	Returns degrees converted to radians.
*/
double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}
