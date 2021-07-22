/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_physmat.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 17:11:40 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/22 18:39:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

t_err	parse_physmat(char *line, t_physmat **physmat)
{
	*physmat = ft_calloc(1, sizeof(physmat));
	if (!*physmat)
		return (err_system);
	if (parse_double(line, &(*physmat)->roughness) != err_success)
		return (err_param);
	if (!isclamped((*physmat)->roughness, 0, 1))
		return (err_param);
	return (err_success);
}
