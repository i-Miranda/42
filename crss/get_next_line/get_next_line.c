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
	
	if (!list)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return ;
		if (read(fd, buf, BUFFER_SIZE) < 0)
		{
			free(buf);
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

char	*check_newline(t_list **list)
{
	t_list	*iter;
	int		i;

	if (!list)
		return (NULL);
	iter = *list;
	while (iter->next != NULL)
	{
		i = 0;
		if (iter->content != NULL)
		{
			while (iter->content[i] != '\n' || iter->content[i] != '\0')
				i++;
		}
		iter = iter->next;
	}
	i = 0;
	while (iter->content[i] != '\n' || iter->content[i] != '\0')
		i++;
	if (iter->content[i] == '\n')
		return (build_newline(list));
	return (NULL);
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
		while (iter->next != NULL || iter->content != NULL)
		{
			str[j++] = *(iter->content)++;
			iter = iter->next;
		}
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
	next_line = check_newline(list);
	ft_lst_clear(list);
	return (next_line);
}
