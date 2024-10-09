/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/09 16:42:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_count_chars(t_list **list)
{
	t_list	*iter;
	int		i;
	int		nl_found;
	
	iter = *list;
	i = 0;
	nl_found = 0;
	while (iter)
	{
		while(iter->content[i] != '\0')
		{
			i++;
			if (iter->content[i] == '\n')
			{
				nl_found = 1;
				break;
			}
		}
		if (nl_found == 1)
			break;
		iter = iter->next;
	}
	return (i);
}

// List functions
t_list	**ft_lst_append(t_list **list, char *content)
{
	t_list	*last_node;
	t_list	*new;

	if (!list)
		return (NULL);
	last_node = *list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	new = malloc(sizeof(t_list));
	if (new == NULL)
	{
		ft_lst_clear(list);
		return (NULL);
	}
	new->content = content;
	last_node->next = new;
	return (list);
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
