/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/21 12:16:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_list	*ft_after_nl(t_list **list, int nl_position)
{
	t_list	*last;
	char	*buf;
	int		i;
	int		j;

	last = ft_lst_last(list);
	ft_lst_clear(list, last);
	i = nl_position;
	while (last->content[nl_position])
		i++;
	buf = malloc((i - nl_position + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	j = 0;
	while (last->content[nl_position])
		buf[j++] = last->content[nl_position++];
	buf[j] = '\0';
	free(last->content);
	last->content = buf;
	return (last);
}

static void	ft_build_list(t_list **list, int fd)
{
	t_list	*new;
	t_list	*last;
	char	*buf;
	ssize_t	bytes_read;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(new);
		ft_lst_clear(list, NULL);
		return ;
	}
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buf);
		free(new);
		ft_lst_clear(list, NULL);
		return ;
	}
	buf[bytes_read] = '\0';
	new->content = buf;
	new->next = NULL;
	if (*list ==NULL)
		*list = new;	
	else
	{
		last = ft_lst_last(list);
		if (last == NULL)
		{
			free(buf);
			free(new);
			ft_lst_clear(list, NULL);
			return ;
		}
		last->next = new;
	}
	while (ft_nl_check(buf) == 0 && bytes_read > 0)
		ft_build_list(list, fd);
}

// Gets the list content, saves it into a string and null terminates it
static char	*build_newline(t_list **list)
{
	t_list	*temp;
	size_t	len;
	size_t	i;
	char	*new_line;

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
	temp = *list;
	while (temp)
	{
		ft_lst_to_string(temp, new_line);
		temp = temp->next;
	}
	new_line[len] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	int				nl_position;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	ft_build_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = build_newline(&list);
	if (!next_line)
	{
		ft_lst_clear(&list, NULL);
		return (NULL);
	}
	nl_position = ft_nl_check(next_line); 
	if (nl_position != 0)
	{
		list = ft_after_nl(&list, nl_position);
		printf("list=%s\n", list->content);
	}
	return (next_line);
}
