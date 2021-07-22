/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collections.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 11:38:25 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/25 23:54:57 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLECTIONS_H
# define COLLECTIONS_H

typedef struct s_list
{
	void			*element;
	struct s_list	*next;
}	t_list;

typedef struct s_dict
{
	char	*key;
	void	*value;
	void	*next;
}	t_dict;

char	lst_addnewfront(t_list **head, void *element);
char	lst_addnewback(t_list **head, void *element);

char	dict_add(t_dict **dict, char *key, void *value);
void	*dict_getvalue(t_dict *dict, char *key);
void	dict_free(t_dict *dict);

#endif
