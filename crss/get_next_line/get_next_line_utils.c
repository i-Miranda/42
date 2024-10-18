/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/18 16:32:17 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	**ft_lst_append(t_list **list, char *content)
{
	t_list	*last_node;
	t_list	*new;

	if (!list)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (*list == NULL)
	{
		*list = new;
		return (list);
	}
	last_node = *list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new;
	return (list);
}

void	ft_lst_to_string(t_list **list, char *str, int i)
{
	t_list	*iter;
	int		j;
	int		k;

	j = 0;
	iter = *list;
	while (iter)
	{
		k = 0;
		while (j < i && iter->content[k] != '\0')
			str[j++] = iter->content[k++];
		iter = iter->next;
	}
}

int	ft_lst_clear(t_list **list)
{
	t_list	*current;
	t_list	*previous;

	if (!list)
		return (0);
	current = *list;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
		free(previous->content);
		free(previous);
	}
	free(current->content);
	free(current);
	free(list);
	return (1);
}
