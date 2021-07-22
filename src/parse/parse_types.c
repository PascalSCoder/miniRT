/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_types.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 14:29:16 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:42:10 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"

/*
**	Parse line to int *out.
**	Returns err_success(0) or err specifier.
*/
t_err	parse_int(char *line, int *out)
{
	if (!check_int(line, '\0'))
		return (err_param);
	*out = ft_atoi(line);
	return (err_success);
}

/*
**	Parse line to double *out.
**	Returns err_success(0) or err specifier.
*/
t_err	parse_double(char *line, double *out)
{
	if (!check_double(line, '\0'))
		return (err_param);
	*out = ft_atof(line);
	return (err_success);
}

/*
**	Parse line to unsigned char *out.
**	Returns err_success(0) or err specifier.
*/
t_err	parse_uchar(char *line, unsigned char *out)
{
	int	tmp;

	if (!check_int(line, '\0'))
		return (err_param);
	tmp = ft_atoi(line);
	if (!int_fits_uchar(tmp))
		return (err_param);
	*out = (unsigned char)tmp;
	return (err_success);
}

/*
**	Parse line to t_vector3 *out.
**	Returns err_success(0) or err specifier.
*/
t_err	parse_vector3(char *line, t_vector3 *out)
{
	if (!check_vector3(line))
		return (err_param);
	out->x = ft_atof(line);
	line = ft_strchr(line, ',') + 1;
	out->y = ft_atof(line);
	line = ft_strchr(line, ',') + 1;
	out->z = ft_atof(line);
	return (err_success);
}

/*
**	Parse line to t_frgb *out.
**	Returns err_success(0) or err specifier.
*/
t_err	parse_rgb(char *line, t_frgb *out)
{
	int	ints[3];

	if (!check_int3(line))
		return (err_param);
	ints[0] = ft_atoi(line);
	if (!int_fits_uchar(ints[0]))
		return (err_param);
	line = ft_strchr(line, ',') + 1;
	ints[1] = ft_atoi(line);
	if (!int_fits_uchar(ints[1]))
		return (err_param);
	line = ft_strchr(line, ',') + 1;
	ints[2] = ft_atoi(line);
	if (!int_fits_uchar(ints[2]))
		return (err_param);
	out->r = ints[0];
	out->g = ints[1];
	out->b = ints[2];
	return (err_success);
}
