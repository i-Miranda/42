/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/21 16:44:43 by ivmirand         ###   ########.fr       */
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
	if (!list->content)
		return ;
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
	{
		*list = NULL;
	}
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

t_list	*ft_fd_to_lst(t_list **list, int fd)
{
	t_list	*new;
	t_list	*last;
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[bytes_read] = '\0';
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buf);
		return (NULL);
	}
	new->content = buf;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		last = ft_lst_last(list);
		last->next = new;
	}
	return (*list);
}
