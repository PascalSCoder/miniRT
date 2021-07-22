/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pascal <pascal@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 22:18:31 by pascal        #+#    #+#                 */
/*   Updated: 2021/04/02 12:55:29 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# define BUFFER_SIZE 1000

enum e_result
{
	error = -1,
	file_done = 0,
	line_done = 1,
	processing = 2
};

typedef struct s_fd
{
	int					fd;
	size_t				end;
	size_t				start;
	struct s_fd			*next;
	struct s_fd			*prev;
	struct s_bufferlist	*buffers;
	struct s_bufferlist	*last;
}				t_fd;

typedef struct s_bufferlist
{
	char				*buffer;
	struct s_bufferlist	*next;
}				t_bufferlist;

size_t			ft_strncpy(char *dest, char *buffer, size_t i);
int				get_next_line(int fd, char **line);
t_bufferlist	*lstcreateadd(t_bufferlist **lst);
size_t			ft_lstsize(t_bufferlist *lst);
void			ft_lstclear(t_fd **fd_list, t_fd *fd_data,
					t_bufferlist *lst, int result);
t_fd			*fd_fetch(t_fd **lst, int fd);

#endif
