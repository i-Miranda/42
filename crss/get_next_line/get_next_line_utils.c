/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/30 18:31:57 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lst_last(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

// Gets the list content and returns the len
size_t	get_newline_len(t_list **list)
{
	t_list	*temp;
	size_t	len;
	size_t	i;

	temp = *list;
	len = 0;
	while (temp)
	{
		i = 0;
		while (temp->content && i < BUFFER_SIZE && temp->content[i])
		{	
			i++;
			if (temp->content[i - 1] == '\n')
				return (len + i);
		}
		len += i;
		temp = temp->next;
	}
	return (len); 
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
		*list = NULL;
	else
		*list = current;
}

ssize_t	ft_fd_to_lst(t_list *list, int fd)
{
	char	*buf;
	ssize_t	bytes_read;
	t_list	*new;

	bytes_read = -1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (bytes_read);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buf);
		return (bytes_read);
	}
	buf[bytes_read] = '\0';
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buf);
		return (bytes_read);
	}
	new->content = buf;
	new->next = NULL;
	if (list == NULL)
	{
		free(new);
		free(buf);
		return (-1);
	}
	list->next = new;
	return (bytes_read);

}

// -1 if found
int	ft_nl_check(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len++;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (i);
		i++;	
	}
	return (-1);
}
