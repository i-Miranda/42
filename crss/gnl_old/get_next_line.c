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

static void	polish_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[i++])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	ft_lst_clear(list);
}

void	ft_build_list(t_list **list, int fd)
{
	char	*buf;
	ssize_t	bytes_read;

	while (check_newline(list) <= 0)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = '\0';
 		ft_lst_append(list, buf);
	}
}

int	check_newline(t_list **list)
{
	t_list	*iter;
	int		total_chars;
	int		i;

	total_chars = 0;
	iter = *list;
	while (iter && iter->content) 
	{
		i = 0;
		while (iter->content[i] != '\0')
		{ 
			total_chars++;
			if (iter->content[i] == '\n')
				return (total_chars);
			i++;
		}
		iter = iter->next;
	}
	return (-total_chars);
}

char	*build_newline(t_list **list)
{
	char	*str;
	int		i;

	i = check_newline(list);
	if (i < 0)
		return (NULL);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
	{
		ft_lst_clear(list);
		return (NULL);
	}
	ft_lst_to_string(list, str, i);
	return (str);
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
	if (check_newline(&list) >= 0)
	{
		next_line = build_newline(&list);
		return (next_line);
	}
	ft_lst_clear(&list);
	return (NULL);
}
