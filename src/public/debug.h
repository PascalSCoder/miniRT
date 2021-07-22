/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/16 16:11:00 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/02 12:52:47 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "datatypes.h"
# include <stdio.h>

void	printm4(t_matrix4 mtrx, char *prefix);
void	printv3(t_vector3 vect, char *prefix);
void	printfrgb(t_frgb rgb, char *prefix);
void	printrgb(t_rgb rgb, char *prefix);
t_ray	*debugray(t_scene *scene, int x, int y);

#endif
