/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tools.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 19:48:44 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/16 11:39:40 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	strs_count(char **strs)
{
	size_t	len;

	len = 0;
	while (strs[len])
		len++;
	return (len);
}

char	isclamped(double n, double min, double max)
{
	if (n < min || n > max)
		return (0);
	return (1);
}
