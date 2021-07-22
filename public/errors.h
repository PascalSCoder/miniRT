/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 09:40:31 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 12:52:56 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_err
{
	err_success,
	err_system,
	err_args,
	err_open,
	err_identifier,
	err_param,
	err_splitcount,
}	t_err;

void	program_exit(t_err type, char *msg);

#endif
