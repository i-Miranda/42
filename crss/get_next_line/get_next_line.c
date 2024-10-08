/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/05 09:55:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*build_newline(t_list **list)
{
	char	*str;
	int		i;
	int		j;
	t_list	*iter;

	if (!list)
		return (NULL);
	iter = *list;
	i = 0;
	while (*list)
	{
		j = 0;
		while(iter->content[j] != '\0')
		{
			if (iter->content[j] == '\n')
			{
				i++;
				j++;
				break;
			}
		}
		iter = iter->next;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	iter = *list;
	while (i > 0)
	{
		while (iter->next != NULL || iter->content != NULL)
		{
			if (iter->content != NULL)
				str[i++] = *iter->content++;
			iter = iter->next;
		}
	}
	return (str);
}

char	*check_newline(t_list **lst)
{
	t_list	*iter;
	int		i;

	if (!lst)
		return (NULL);
	iter = *lst;
	i = 0;
	while (iter->next != NULL)
	{
		if (iter->content != NULL)
		{
			while (iter->content[i] != '\n' || iter->content[i] != '\0')
				i++;
		}
		if (iter->next != NULL)
			iter = iter->next;
	}
	if (iter->content[i] == '\n')
		return (build_newline(lst));
	return (NULL);
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
	return (next_line);
}
