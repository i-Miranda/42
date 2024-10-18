/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/18 15:38:04 by ivmirand         ###   ########.fr       */
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
		buf[BUFFER_SIZE] = '\0';
		if (bytes_read < 0 || ft_lst_append(list, buf) == NULL)
		{
			free(buf);
			return ;
		}
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
	i = 0;
	while (iter && iter->content[i] != '\0')
	{
		total_chars++;
		if (iter->content[i] == '\n')
		{
			if (total_chars == 0)
				return (total_chars);
			else
				return (total_chars + 1);
		}
		i++;
		iter = iter->next;
	}
	return (-total_chars);
}

char	*build_newline(t_list **list)
{
	char	*str;
	int		i;
	int		j;
	t_list	*iter;

	if (!list)
		return (NULL);
	i = check_newline(list);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	iter = *list;
	while (j < i)
	{
		if (iter->next != NULL || iter->content != NULL)
			while (*iter->content != '\0')
				str[j++] = *iter->content++;
		iter = iter->next;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	**list;
	char			*next_line;
	int				nl_check;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_build_list(list, fd);
	if (!list)
		return (NULL);
	nl_check = check_newline(list);
	if (nl_check >= 0)
	{
		next_line = build_newline(list);
		ft_lst_clear(list);
		return (next_line);
	}
	else
		ft_lst_clear(list);
	return (NULL);
}
