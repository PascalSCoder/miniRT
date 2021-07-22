/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 11:48:21 by pascal        #+#    #+#                 */
/*   Updated: 2020/11/02 12:36:09 by pascal        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch >= 'A' && ch <= 'Z')
		ch += 32;
	return (ch);
}
