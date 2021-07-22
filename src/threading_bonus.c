/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threading_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 22:43:05 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/09 11:31:46 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/rt.h"
#include <pthread.h>
#include <stdlib.h>

static void	destroy_threads(t_scene *scene, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < scene->threadc)
	{
		if (pthread_join(threads[i], NULL) != 0)
			program_exit(err_system, "Failed to join a thread.");
		i++;
	}
	free(threads);
}

void	create_threads(t_scene *scene, t_frgb *frame)
{
	pthread_t	*threads;
	t_thread	*thread;
	int			i;

	if (scene->threadc == 1)
	{
		render_thread(&(t_thread){.frame = frame, .id = 0, .scene = scene});
		return ;
	}
	threads = malloc(scene->threadc * sizeof(pthread_t));
	thread = malloc(scene->threadc * sizeof(t_thread));
	if (!threads || !thread)
		program_exit(err_system, 0);
	i = 0;
	while (i < scene->threadc)
	{
		thread[i].frame = frame;
		thread[i].scene = scene;
		thread[i].id = i;
		if (pthread_create(&threads[i], NULL, &render_thread, &thread[i]) != 0)
			program_exit(err_system, "Failed to start new thread.");
		i++;
	}
	destroy_threads(scene, threads);
	free(thread);
}
