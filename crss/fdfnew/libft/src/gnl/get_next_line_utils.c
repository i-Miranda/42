/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 13:38:45 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Gets the list content and returns the entire len or up to newline
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
		while ((char *)temp->content && ((char *)temp->content)[i])
			if (((char *)temp->content)[i++] == '\n')
				return (len + i);
		len += i;
		temp = temp->next;
	}
	return (len);
}

// Clears list, if a stop is added clears list until stop
void	clear_lst_to_stop(t_list **list, t_list *stop)
{
	t_list	*next;

	while (*list != stop)
	{
		next = (*list)->next;
		free((*list)->content);
		(*list)->content = NULL;
		free(*list);
		*list = next;
	}
	if (stop == NULL)
		list = NULL;
}

void	ft_fd_to_lst(t_list *list, int fd, ssize_t *bytes_read)
{
	char	*buf;
	t_list	*temp;

	*bytes_read = -1;
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
	temp = ft_lstlast(list);
	temp->next = malloc(sizeof(t_list));
	if (temp->next == NULL)
	{
		free(buf);
		*bytes_read = -1;
		return ;
	}
	temp->next->content = buf;
	temp->next->next = NULL;
}

// -1 if nl not found
int	ft_nl_check(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (str[i] == '\n')
			return (i);
	return (-1);
}
