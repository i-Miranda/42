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
	if (new == NULL)
	{
		ft_lst_clear(list);
		return (NULL);
	}
	new->content = content;
	last_node->next = new;
	return (list);
}

void	ft_build_list(t_list **list, int fd)
{
	char	*buf;
	
	while (!list)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!list)
			return ;
		if (read(fd, buf, BUFFER_SIZE) < 0)
		{
			free(buf);
			return ;
		}
		buf[BUFFER_SIZE] = '\0';
		ft_lst_append(list, buf);
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

