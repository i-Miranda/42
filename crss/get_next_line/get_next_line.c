/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/21 16:46:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

static t_list	*ft_after_nl(t_list **list, int *nl_position)
{
	int		i;
	t_list	*last;
	char	*buf;

	i = *nl_position;
	last = ft_lst_last(*list);
	if (last == NULL || last->content == NULL)
	{
		//printf("last is NULL or last->content is NULL. Returning NULL. : ft_after_nl\n");
		if (last)
			ft_lst_clear(&last, NULL);
		return (NULL);
	}
	while (last->content[i])
		i++;
	if (i - *nl_position < -1)
	{
		ft_lst_clear(list, last);
		return (NULL);
	}
	buf = malloc((i - *nl_position + 1) * sizeof(char));
	if (!buf)
		return (last);
	(*nl_position)++;
	i = 0;
	while (last->content[*nl_position]) //paco complains about this fsanitize
		buf[i++] = last->content[(*nl_position)++];
	buf[i] = '\0';
	free(last->content);
	last->content = buf;
	//*nl_position = ft_nl_check(last->content, i);
	ft_lst_clear(list, last);
	return (last);
}

// Gets the list content and returns the len
static size_t	build_newline(t_list **list)
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
			if (temp->content[i] == '\n')
				return (len + i + 1);
			i++;
		}
		len += i;
		temp = temp->next;
	}
	return (len);
}

static ssize_t	ft_build_list(t_list **list, int fd, int *nl_position)
{
	ssize_t bytes_read;
	t_list	*last;

	bytes_read = -1;
	if (*list == NULL)
	{
		*list = malloc(sizeof(t_list));
		if (*list == NULL)
			return (bytes_read);
		(*list)->content = NULL;
		(*list)->next = NULL;
	}
	last = ft_lst_last(*list);
	while (last)
	{
		bytes_read = ft_fd_to_lst(last, fd);
		if (bytes_read <= 0)
			return (bytes_read);
		last = last->next;
		if (last->content != NULL)
			*nl_position = ft_nl_check(last->content, BUFFER_SIZE);
		if (*nl_position != 0)
			return (bytes_read);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				nl_position;
	ssize_t			bytes_read;	

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	nl_position = -1;
	bytes_read = 1;
	while (nl_position <= 0 && bytes_read > 0)
	{
		bytes_read = ft_build_list(&list, fd, &nl_position);
		if (list == NULL)
			return (NULL);
		next_line = ft_lst_to_string(list, build_newline(&list));
	}
	//printf("next_line is %s : get_next_line\n", next_line);
	list = ft_after_nl(&list, &nl_position);
	if (list == NULL)
		return (NULL);
	if (bytes_read <= 0)
		ft_lst_clear(&list, NULL);
	if (bytes_read < 0)
	{
		free(next_line);
		return ("");
	}
	return (next_line);
}
