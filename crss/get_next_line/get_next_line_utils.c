/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lst_last(t_list **list)
{
	t_list	*last_node;

	if (!list || !*list)
		return (NULL);
	last_node = *list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

// Copies list content into a string
void	ft_lst_to_string(t_list *list, char *str, size_t *i)
{
	size_t	j;

	j = 0;
	while (list->content[j] != '\0')
	{
		str[*i] = list->content[j];
		(*i)++;
		j++;
	}
	str[*i] = '\0';
}

// Clears list, if a stop is added clears list until stop
void	ft_lst_clear(t_list **list, t_list *stop)
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current != stop)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	if (stop == NULL)
		list = NULL;
	else
		*list = current;
}

int	ft_nl_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}
