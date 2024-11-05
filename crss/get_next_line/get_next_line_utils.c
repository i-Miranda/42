/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/01 18:28:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lst_last(t_list *list)
{
	t_list	*temp;

	temp = list;
	if (temp == NULL)
		return (NULL);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
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
	t_list	*next;

	while (*list != stop)
	{
		next = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next;
	}
	if (stop == NULL)
		*list = NULL;
}

void	ft_fd_to_lst(t_list *list, int fd, ssize_t *bytes_read)
{
	char	*buf;
	t_list	*temp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	*bytes_read = read(fd, buf, BUFFER_SIZE);
	if (*bytes_read <= 0)
	{
		free(buf);
		return ;
	}
	buf[*bytes_read] = '\0';
	temp = ft_lst_last(list);
	temp->next = malloc(sizeof(t_list));
	if (temp->next == NULL)
	{
		free(buf);
		return ;
	}
	temp->next->content = buf;
	temp->next->next = NULL;
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
