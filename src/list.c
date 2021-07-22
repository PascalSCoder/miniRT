/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pspijkst <pspijkst@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 11:30:45 by pspijkst      #+#    #+#                 */
/*   Updated: 2021/03/29 10:30:12 by pspijkst      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../public/collections.h"
#include "../public/libft.h"

char	lst_addnewfront(t_list **head, void *element)
{
	t_list	*new;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new)
		return (0);
	new->element = element;
	new->next = *head;
	*head = new;
	return (1);
}

char	lst_addnewback(t_list **head, void *element)
{
	t_list	*new;
	t_list	*tmp;

	new = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!new)
		return (0);
	new->element = element;
	new->next = 0;
	if (!*head)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
