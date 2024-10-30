/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/28 11:38:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>


static t_list	*ft_after_nl(t_list **list)
{
	int		i;
	int		c_len;
	int		b_len;
	t_list	*last;
	char	*buf;

	last = ft_lst_last(*list);
	i = -1;
	b_len = 0;
	c_len = 0;
	while (last->content[c_len])
	{
		if (i < 0 && (last->content)[c_len] == '\n')
			i = c_len;
		c_len++;	
	}
	buf = malloc((c_len - i + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (i < c_len)
		buf[b_len++] = last->content[++i];
	buf[b_len] = '\0';
	free(last->content);
	last->content = buf;
	last->next = NULL;
	ft_lst_clear(&((*list)->next), last);
	return (last);
}

// Gets the list content and returns the len
static size_t	get_newline_len(t_list **list)
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

static void	ft_build_list(t_list **list, int fd, ssize_t *bytes_read)
{
	t_list	*last;

	if (*list == NULL)
	{
		*list = malloc(sizeof(t_list));
		if (*list == NULL)
			return ;
		(*list)->content = NULL;
		(*list)->next = NULL;
	}
	if ((*list)->content != NULL)
	{
		*bytes_read = ft_nl_check((*list)->content);
		if (*bytes_read > 0 || 
				(*bytes_read == 0 && (*list)->content[0] == '\n'))
			return ;
	}
	last = ft_lst_last(*list);
	while (last)
	{
		*bytes_read = ft_fd_to_lst(last, fd);
		if (*bytes_read <= 0)
			return ;
		last = last->next;
		if (ft_nl_check(last->content) >= 0)
			return ;	
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*next_line;
	ssize_t			bytes_read;	

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = -1;
	ft_build_list(&head, fd, &bytes_read);
	if (bytes_read <= 0)
	{
		ft_lst_clear(&head, NULL);
		return (NULL);
	}
	next_line = ft_lst_to_string(&head, get_newline_len(&head));
	head->next = ft_after_nl(&head);
	return (next_line);
}
