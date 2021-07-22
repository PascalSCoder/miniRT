/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:16:28 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 11:22:28 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../public/parse.h"
#include "../../public/libft_ext.h"
#include "../../public/get_next_line.h"
#include "../../public/collections.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void	fill_dict(t_dict **dict)
{
	char	count;

	count = 0;
	count += dict_add(dict, "R", &parse_r);
	count += dict_add(dict, "A", &parse_a);
	count += dict_add(dict, "c", &parse_c);
	count += dict_add(dict, "l", &parse_l);
	count += dict_add(dict, "pl", &parse_pl);
	count += dict_add(dict, "sp", &parse_sp);
	count += dict_add(dict, "sq", &parse_sq);
	count += dict_add(dict, "cy", &parse_cy);
	count += dict_add(dict, "tr", &parse_tr);
	count += dict_add(dict, "t", &parse_t);
	count += dict_add(dict, "dl", &parse_dl);
	count += dict_add(dict, "aa", &parse_aa);
	count += dict_add(dict, "md", &parse_md);
	count += dict_add(dict, "bg", &parse_bg);
	count += dict_add(dict, "ENABLE_DEBUG", &enable_debug);
	if (count != 15)
		program_exit(err_system, "Parse dictionary failed to initialize.");
}

static t_err	parse_line(t_scene *scene, char *line, t_dict *dict)
{
	t_err	(*parsef)(t_scene*, char**);
	t_err	result;
	char	**splits;

	splits = ft_split_set(line, " \t");
	if (!splits)
		program_exit(err_system, 0);
	parsef = dict_getvalue(dict, *splits);
	if (!parsef)
		program_exit(err_identifier, line);
	result = parsef(scene, splits + 1);
	ft_split_free(splits);
	return (result);
}

static void	read_file(t_scene *scene, int fd, t_dict *dict)
{
	t_err	parse_result;
	int		gnl_result;
	char	*line;

	while (1)
	{
		gnl_result = get_next_line(fd, &line);
		if (gnl_result == -1)
			program_exit(err_system, 0);
		if (line[0] != '\0')
		{
			parse_result = parse_line(scene, line, dict);
			if (parse_result != err_success)
				program_exit(parse_result, line);
		}
		free(line);
		if (gnl_result == 0)
			break ;
	}
}

t_scene	*initstate_parse(char *filename)
{
	t_scene	*scene;
	t_dict	*dict;
	int		fd;

	dict = 0;
	fill_dict(&dict);
	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!scene)
		program_exit(err_system, 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		program_exit(err_open, 0);
	read_file(scene, fd, dict);
	check_scene(scene);
	dict_free(dict);
	return (scene);
}
