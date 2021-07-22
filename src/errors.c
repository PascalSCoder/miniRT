/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:31:43 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 13:04:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/errors.h"
#include "../public/libft.h"
#include <stdlib.h>

void	program_exit(t_err type, char *msg)
{
	static const char	*errtable[] = {
		"A system error occured.",
		"Invalid argument(s). Valid: ./minirt [*.rt] optionally: [--save]",
		"The .rt file couldn't be opened.",
		"Encountered unhandled identifier in .rt file.",
		"Invalid parameter for identifier encountered.",
		"Invalid amount of parameters for identifier.",
	};

	if (type > 0)
	{
		ft_putendl_fd("Error", 1);
		ft_putendl_fd((char *)errtable[type - 1], 1);
	}
	if (msg)
		ft_putendl_fd(msg, 1);
	exit(0);
}
