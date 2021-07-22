/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:32:13 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/03 14:35:20 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "datatypes.h"

t_scene	*initstate_parse(char *args);
t_frgb	*initstate_render(t_scene *scene);
void	initstate_bmp(t_rgb *frame, t_res res);
void	initstate_mlx(t_rgb *frame, t_scene *scene);

void	init_scene(t_scene *scene);
void	init_mlx(t_scene *scene);
t_rgb	*frgb_to_rgb(t_frgb *frame, t_res res);

#endif
