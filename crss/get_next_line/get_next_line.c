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

static t_list	*ft_after_nl(t_list **list, int nl_position)
{
	int		i;
	t_list	*last;
	char	*buf;

	i = nl_position;
	last = ft_lst_last(list);
	if (!last || !last->content)
		return (NULL);
	ft_lst_clear(list, last);
	if (last->content[nl_position] == '\0')
	{
		free(last->content);
		last->content = NULL;
		last->next = NULL;
		return (last);
	}
	while (last->content[i] != '\0')
		i++;
	buf = malloc((i - nl_position + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	i = 0;
	while (last->content[nl_position] != '\0')
		buf[i++] = last->content[nl_position++];
	buf[i] = '\0';
	free(last->content);
	last->content = buf;
	nl_position = ft_nl_check(last->content);
	if (nl_position > 0)
		ft_after_nl(list, nl_position);
	return (last);
}

// Gets the list content, saves it into a string and null terminates it
static char	*build_newline(t_list **list)
{
	t_list	*temp;
	size_t	len;
	size_t	i;
	char	*new_line;

	if (*list == NULL)
		return (NULL);
	temp = *list;
	len = 0;
	while (temp)
	{
		i = 0;
		if (temp->content)
		{
			while (temp->content[i] != '\0')
				i++;
			len += i;
		}
		temp = temp->next;
	}
	new_line = malloc((len + 1) * sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	new_line[0] = '\0';
	temp = *list;
	while (temp)
	{
		ft_lst_to_string(temp, new_line, &i);
		temp = temp->next;
	}
	return (new_line);
}

static t_list	*ft_build_list(t_list **list, int fd, int *nl_position)
{
	while (1)
	{
		*list = ft_fd_to_lst(list, fd);
		if (!*list || !ft_lst_last(list)->content)
			return (NULL);
		*nl_position = ft_nl_check(ft_lst_last(list)->content);
		if (*nl_position > 0)
			break ;
		if (*nl_position < 0)
			break ;
	}
	return (*list);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				nl_position;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	list = NULL;
	next_line = NULL;
	nl_position = 0;
	list = ft_build_list(&list, fd, &nl_position);
	if (!list)
		return (NULL);
	next_line = build_newline(&list);
	if (nl_position != 0)
		list = ft_after_nl(&list, nl_position);
	ft_lst_clear(&list, NULL);
	return (next_line);
}
