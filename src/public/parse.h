/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 16:42:17 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/03 15:12:49 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "datatypes.h"
# include "errors.h"
# include "libft.h"
# include "libft_ext.h"
# include "collections.h"

t_err		parse_vector3(char *line, t_vector3 *out);
t_err		parse_rgb(char *line, t_frgb *out);
t_err		parse_int(char *line, int *out);
t_err		parse_uchar(char *line, unsigned char *out);
t_err		parse_double(char *line, double *out);
t_err		parse_physmat(char *line, t_physmat **physmat);

size_t		strs_count(char **strs);
char		isclamped(double n, double min, double max);

char		int_fits_uchar(int n);
size_t		check_int(char *line, char end);
size_t		check_double(char *line, char end);
char		check_int3(char *line);
char		check_vector3(char *line);
void		check_scene(t_scene *scene);

t_err		parse_r(t_scene *scene, char **line);
t_err		parse_a(t_scene *scene, char **line);
t_err		parse_c(t_scene *scene, char **line);
t_err		parse_l(t_scene *scene, char **line);
t_err		parse_pl(t_scene *scene, char **line);
t_err		parse_sp(t_scene *scene, char **line);
t_err		parse_sq(t_scene *scene, char **line);
t_err		parse_cy(t_scene *scene, char **line);
t_err		parse_tr(t_scene *scene, char **line);
t_err		parse_dl(t_scene *scene, char **line);
t_err		parse_aa(t_scene *scene, char **line);
t_err		parse_t(t_scene *scene, char **line);
t_err		parse_md(t_scene *scene, char **line);
t_err		parse_bg(t_scene *scene, char **line);
t_err		enable_debug(t_scene *scene, char **strs);

#endif
