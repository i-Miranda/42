/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/01 14:24:30 by ivmirand         ###   ########.fr       */
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

	i = -1;
	b_len = 0;
	c_len = 0;
	last = ft_lst_last(*list);
	if (last == NULL || last->content == NULL)
		return (NULL);
	while (last->content[c_len] != '\0')
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
	if (last->content[0] != '\0')
		ft_lst_clear(&(*list)->next, last);
	else
	{
		ft_lst_clear(&(*list)->next, NULL);
		(*list)->next = NULL;
		last = NULL;
	}
	return (last);
}

static t_list	*ft_head_check(t_list **list, ssize_t *bytes_read)
{
	t_list *temp;

	temp = *list;
	if (temp == NULL)
	{
		temp = malloc(sizeof(t_list));
		if (temp == NULL)
			return (NULL);
		temp->content = NULL;
		temp->next = NULL;
	}
	if (temp->next != NULL)  
	{
		if(temp->next->content != NULL)
		{
			*bytes_read = ft_nl_check(temp->next->content);
			temp->next = ft_after_nl(&temp);
			return (temp);
		}
	} 
	return (temp);
}

// Copies list content into a string
static char	*ft_lst_to_string(t_list **list, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	t_list	*temp;

	temp = *list;
	str = malloc((len + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (temp)
	{
		j = 0;
		while (temp->content && temp->content[j] && i < len)
		{
			str[i] = temp->content[j++];
			if (str[i++] == '\n')
			{
				str[i] = '\0';
				return (str);
			}
		}
		temp = temp->next;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_build_list(t_list **list, int fd, ssize_t *bytes_read)
{
	t_list	*last;

	*list = ft_head_check(list, bytes_read);
	last = *list;
	if (last->next && last->next->content)
		return ;
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
	next_line = ft_lst_to_string(&head, get_newline_len(&head));
	if (bytes_read <= 0)
	{
		ft_lst_clear(&head, NULL);
		if (bytes_read < 0)
		{
			free(next_line);
			return (NULL);
		}
	}
	if (next_line[0] == '\0')
	{
		free(next_line);
		next_line = NULL;
	}
	if (head)
		head->next = ft_after_nl(&head);
	return (next_line);
}
