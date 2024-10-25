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
	ft_lst_clear(list, last);
	if (last == NULL || last->content == NULL)
	{
		printf("last is NULL or last->content is NULL. Returning NULL. : ft_after_nl\n");
		return (NULL);
	}
	if (*nl_position >= (int)strlen(last->content))
		return (NULL);
	if (last->content[*nl_position] == '\0')
	{
		printf("last->content at nl_position == nulterminator. clearing last. : ft_lst_clear\n");
		ft_lst_clear(&last, NULL);
		return (last);
	}
	while (last->content[i] != '\0')
		i++;
	buf = malloc((i - *nl_position + 1) * sizeof(char));
	if (!buf)
		return (last);
	i = 0;
	while (last->content[*nl_position] != '\0')
		buf[i++] = last->content[*nl_position++];
	buf[i] = '\0';
	free(last->content);
	last->content = buf;
	*nl_position = ft_nl_check(last->content);
	printf("nl_position is %d: ft_after_nl\n", *nl_position);
	return (last);
}

// Gets the list content, saves it into a string and null terminates it
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
		if (temp->content)
		{
			while (i < BUFFER_SIZE && temp->content[i] != '\0')
				i++;
			len += i;
		}
		temp = temp->next;
	}
	return (len);
}

static ssize_t	ft_build_list(t_list **list, int fd, int *nl_position)
{
	t_list *last;
	ssize_t bytes_read;

	last = *list;
	bytes_read = -1;
	if (last == NULL)
	{
		last = malloc(sizeof(t_list));
		if (last == NULL)
			return (bytes_read);
		last->content = NULL;
		last->next = NULL;
		*list = last;
	}
	last = ft_lst_last(*list);
	while (last)
	{
		bytes_read = ft_fd_to_lst(last, fd);
		if (bytes_read <= 0)
			return (bytes_read);
		last = last->next;
		if (last->content != NULL)
		{
			//printf("last->content is %s : ft_build_list\n", last->content);
			*nl_position = ft_nl_check(last->content);
		}
		else
			printf("last->content is NULL.: ft_build_list\n");
		if (*nl_position != 0)
		{
			//printf("nl_postion != 0. breaking loop. : ft_build_list\n");			
			return (bytes_read);
		}
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
	while (nl_position != 0 && bytes_read > 0)
	{
		bytes_read = ft_build_list(&list, fd, &nl_position);
		if (list == NULL)
			return (NULL);
		next_line = ft_lst_to_string(list, build_newline(&list));
	}
	printf("next_line is %s : get_next_line\n", next_line);
	list = ft_after_nl(&list, &nl_position);
	if (bytes_read <= 0)
		ft_lst_clear(&list, NULL);
	if (bytes_read < 0)
	{
		printf("bytes_read < 0. Returning NULL : get_next_line\n");
		return (NULL);
	}
	return (next_line);
}
