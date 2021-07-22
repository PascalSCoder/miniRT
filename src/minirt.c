/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:31:33 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/05/01 22:01:36 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/state.h"
#include "../public/libft.h"
#include "../public/errors.h"
#include "../public/gmath.h"
#include <stdlib.h>

#include "../public/debug.h"

static char	has_rt_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i >= 3)
	{
		if (ft_strncmp(str + i - 3, ".rt", 3) == 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char **args)
{
	t_scene	*scene;
	t_rgb	*frame;

	if (argc != 2 && !(argc == 3 && !ft_memcmp(args[2], "--save", 7)))
		program_exit(err_args, 0);
	if (!has_rt_extension(args[1]))
		program_exit(err_open, "The file specified is not a .rt file.");
	scene = initstate_parse(args[1]);
	if (argc == 2)
		init_mlx(scene);
	init_scene(scene);
	frame = frgb_to_rgb(initstate_render(scene), scene->res);
	if (argc == 2)
		initstate_mlx(frame, scene);
	else
		initstate_bmp(frame, scene->res);
	exit(0);
	return (0);
}
