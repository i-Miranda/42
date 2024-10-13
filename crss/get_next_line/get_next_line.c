/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/09 17:31:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_build_list(t_list **list, int fd)
{
	char	*buf;
	ssize_t	bytes_read;
	
	while (!list)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			ft_lst_clear(list);
			return ;
		}
		buf[BUFFER_SIZE] = '\0';
		if (ft_lst_append(list, buf) == NULL)
		{
			free(buf);
			ft_lst_clear(list);
		}
	}
}

int	check_newline(t_list **list)
{
	t_list	*iter;
	int		i;
	int		nl_found;

	if (!list)
		return (0);
	iter = *list;
	nl_found = 0;
	while (iter->next != NULL)
	{
		i = 0;
		if (iter->content != NULL)
			while (iter->content[i] != '\0')
			{
				if (iter->content[i] == '\n')
				{
					nl_found = 1;
					break;
				}
				i++;
			}
		if (nl_found == 1)
			break;
		iter = iter->next;
	}
	i = 0;
	while (iter->content[i] != '\n' || iter->content[i] != '\0')
		i++;
	return (nl_found);
}

char	*build_newline(t_list **list)
{
	char	*str;
	int		i;
	int		j;
	t_list	*iter;

	if (!list)
		return (NULL);
	i = ft_count_chars(list);
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
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	**list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_build_list(list, fd);
	if (!list)
		return (NULL);
	if (check_newline(list) != 0)
	{
		next_line = build_newline(list);
		ft_lst_clear(list);
		return (next_line);
	}
	else
		ft_lst_clear(list);
	return (NULL);
}
