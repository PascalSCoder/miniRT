/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/13 12:04:55 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/24 15:41:26 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/libft.h"

/*
**	Returns 0 or 1 depending on whether n fits into unsigned char.
*/
char	int_fits_uchar(int n)
{
	if (n < 0 || n > 255)
		return (0);
	return (1);
}

/*
**	Strictly checks a string for other characters than digits until the
**	end character is reached.
**	Accepted formats are: '123' '-123'.
**	Returns 0 on failure or the amount of digits in the string on success.
*/
size_t	check_int(char *line, char end)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit(line[i]) && line[i] != '-')
		return (0);
	i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == end)
		return (i);
	return (0);
}

/*
**	Strictly checks a string on it's format to fit a double, until the
**	end character is reached.
**	Accepted formats are: '1.2' '.2' '1'.
**	Returns 0 on failure or the amount of digits in the string on success.
*/
size_t	check_double(char *line, char end)
{
	size_t	i;

	i = 0;
	if (!ft_isdigit(line[i]) && line[i] != '-')
		return (0);
	i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '.')
	{
		i++;
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
		while (ft_isdigit(line[i]))
			i++;
	}
	if (line[i] == end)
		return (i);
	return (0);
}

/*
**	Strictly checks a string on it's format to fit an int array[3].
**	Accepted format is: 'i,i,i' (see check_int for more information)..
**	Returns 0 on failure or 1 on success.
*/
char	check_int3(char *line)
{
	size_t	i;

	i = check_int(line, ',');
	if (!i)
		return (0);
	line += i + 1;
	i = check_int(line, ',');
	if (!i)
		return (0);
	line += i + 1;
	i = check_int(line, '\0');
	if (!i)
		return (0);
	return (1);
}

/*
**	Strictly checks a string on it's format to fit a vector3.
**	Accepted format is:'d,d,d' (see check_double for more information).
**	Returns 0 on failure or 1 on success.
*/
char	check_vector3(char *line)
{
	size_t	i;

	i = check_double(line, ',');
	if (!i)
		return (0);
	line += i + 1;
	i = check_double(line, ',');
	if (!i)
		return (0);
	line += i + 1;
	i = check_double(line, '\0');
	if (!i)
		return (0);
	return (1);
}
