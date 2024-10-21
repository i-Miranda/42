/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/19 19:23:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Get last node in list, does NOT check for null list
t_list	*ft_lst_last(t_list **list)
{
	t_list	*last_node;

	last_node = *list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

// Copies list content into a string
void	ft_lst_to_string(t_list *list, char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
		i++;
	j = 0;
	while (list->content[j] != '\0')
	{
		str[i] = list->content[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

// Iterates a function along a list (such as free)
void	ft_lst_iter(t_list **list, void (*f)(void *))
{
	t_list	*current;

	current = *list;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}

int	ft_nl_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
