/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/12 14:34:54 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/05 12:59:08 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/datatypes.h"

/*
**	Returns argument n normalized.
*/
double	normalize(double n)
{
	if (n > 1)
		n = 1;
	else if (n < -1)
		n = -1;
	return (n);
}

/*
**	Returns 0 or 1 depending on whether n is normalized.
*/
char	isnormalized(double n)
{
	if (n > 1)
		return (0);
	else if (n < -1)
		return (0);
	return (1);
}
