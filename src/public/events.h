/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   events.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 09:43:29 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 12:53:48 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# ifdef MACOS

#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_CLOSE 53
#  define KEY_NEXTCAM 49
#  define KEY_E 14
#  define KEY_Q 12
#  define KEY_R 15
#  define KEY_F 3
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_BMP 10
#  define KEY_CROSS 17

# else

#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_CLOSE 65307
#  define KEY_NEXTCAM 32
#  define KEY_E 101
#  define KEY_Q 113
#  define KEY_R 114
#  define KEY_F 102
#  define KEY_Z 122
#  define KEY_X 120
#  define KEY_BMP 98
#  define KEY_CROSS 33

# endif

int	key_pressed(int keycode, void *param);
int	mb_pressed(int button, int x, int y, void *param);

#endif
