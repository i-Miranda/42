/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/05 10:00:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	if (new != NULL)
		return (NULL);
	new->content = content;
	last_node->next = new;
	return (list);
}

t_list	**ft_build_list(t_list **list)
{
	if (!list)
	{
		list = malloc(sizeof(t_list *));
		if (!list)
			return (NULL);
		return (list);
	}
	return (list);
}

int	ft_lst_clear(t_list **list)
{
	t_list *current;
	t_list *previous;
	if (!list)
		return (0);
	current = *list;
	previous = NULL;
	while (current->next != NULL)
	{
		previous = current;		
		current = current->next;
		free(previous->content);
		free(previous);
	}
	free(current);
	free(list);
	return (1);
}

char	*build_newline(t_list **list, int nl)
{
	char	*str;
	int		i;
	t_list	*iter;

	str = malloc((nl + 1) * sizeof(list));
	if (!str)
		return (NULL);
	i = 0;
	while (i != nl)
	{
		while (iter->next != NULL || iter->content != NULL)
		{
			if (iter->content != NULL)
				str[i++] = *iter->content++;
			iter = iter->next;
		}
	}
	return (str);
}

char	*check_newline(t_list **lst)
{
	t_list	*iter;
	int		i;

	if (!lst)
		return (NULL);
	iter = *lst;
	i = 0;
	while (iter->next != NULL)
	{
		if (iter->content != NULL)
		{
			while (iter->content[i] != '\n' || iter->content[i] != '\0')
				i++;
		}
		if (iter->next != NULL)
			iter = iter->next;
	}
	if (iter->content[i] == '\n')
		return (build_newline(lst, ++i));
	return (NULL);
}
