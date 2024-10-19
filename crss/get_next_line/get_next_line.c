/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/18 18:24:28 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_after_nl(t_list **list)
{
	t_list *last;
	t_list *temp;

	last = ft_lst_last(list);
	while (*list != last)
	{
		temp = *list;
		*list = temp->next;
		free(temp);
	}
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
		return ;
	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	new->content = buf;
	if (!*list)
		*list = new;
	else
	{
		last = ft_lst_last(list);	
		last->content = buf;
		last->next = new;
	}
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
		while (temp->content[i] != '\0')
			i++;
		len += i;
		temp = temp->next;
	}
	new_line = malloc(len * sizeof(char));
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	ft_build_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = build_newline(&list);
	if (!next_line)
		return (NULL);
	if (ft_nl_check(next_line) == 0)
		return (next_line);
	ft_after_nl(&list);
	return (next_line);
}
