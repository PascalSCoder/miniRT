/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/25 23:24:12 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/04/07 11:23:05 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/collections.h"
#include "../public/libft_ext.h"
#include <stdlib.h>

void	dict_free(t_dict *dict)
{
	t_dict	*tmp;

	while (dict)
	{
		tmp = dict;
		dict = dict->next;
		free(tmp);
	}
}

char	dict_add(t_dict **dict, char *key, void *value)
{
	t_dict	*new;

	new = malloc(sizeof(t_dict));
	if (!new)
		return (0);
	new->key = key;
	new->value = value;
	new->next = *dict;
	*dict = new;
	return (1);
}

void	*dict_getvalue(t_dict *dict, char *key)
{
	while (dict)
	{
		if (ft_strcmp(dict->key, key) == 0)
			return (dict->value);
		dict = dict->next;
	}
	return (0);
}
