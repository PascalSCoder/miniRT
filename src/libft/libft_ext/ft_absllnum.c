/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_absllnum.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 09:32:46 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 12:48:02 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_absllnum(long long num)
{
	unsigned long long	unum;

	unum = 0;
	if (num < 0)
		unum = num * -1;
	else
		unum = num;
	return (unum);
}
