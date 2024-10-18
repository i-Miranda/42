/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/18 17:15:10 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		free(buf);
	}
}

int	check_newline(t_list **list)
{
	t_list	*iter;
	int		total_chars;
	int		i;

	if (!list)
		return (0);
	total_chars = 0;
	iter = *list;
	while (iter) 
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

	if (!list)
		return (NULL);
	i = check_newline(list);
	if (i < 0)
		return (NULL);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_lst_to_string(list, str, i);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
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
