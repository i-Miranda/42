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

char	*get_next_line(int fd)
{
	static t_list	**list;
	char			*buf;
	char			*next_line;

	if (ft_build_list(list) == NULL)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	if (read(fd, buf, BUFFER_SIZE) < 0)
	{
		free(buf);
		return (NULL);
	}
	buf[BUFFER_SIZE + 1] = '\0';
	*list = ft_lst_new(buf);
	if (!list)
		return (NULL);
	next_line = check_newline(list);
	if (!next_line)
		get_next_line(fd);
	free(buf);
	ft_lst_clear(list);
	return (next_line);
}
