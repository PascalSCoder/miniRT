/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_to_uchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/15 16:26:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/22 12:02:44 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned char	int_to_uchar(int i)
{
	if (i < 0)
		i = 0;
	if (i > 255)
		i = 255;
	return ((unsigned char)i);
}
