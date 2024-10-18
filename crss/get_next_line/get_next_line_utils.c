/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/18 18:15:14 by ivmirand         ###   ########.fr       */
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
		*list = new;
	else
	{
		last_node = *list;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new;
	}
	return (list);
}

// Turns the list content into a string and null terminates it
void	ft_lst_to_string(t_list **list, char *str, int len)
{
	t_list	*iter;
	int		i;
	int		j;

	i = 0;
	iter = *list;
	while (iter)
	{
		j = 0;
		while (i < len && iter->content[j] != '\0')
			str[i++] = iter->content[j++];
		iter = iter->next;
	}
	str[i] = '\0';
}

void	ft_lst_clear(t_list **list)
{
	t_list	*current;
	t_list	*next_node;

	current = *list;
	while (current)
	{
		next_node = current->next;
		free(current->content);
		free(current);
		current = next_node;
	}
	list = NULL;
}
