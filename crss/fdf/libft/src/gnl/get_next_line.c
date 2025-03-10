/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 13:36:10 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static t_list	*ft_leftovers(t_list **list, t_list *last, int i, int c_len)
{
	int		b_len;
	char	*buf;

	b_len = 0;
	if (i < 0)
	{
		clear_lst_to_stop(list, NULL);
		return (NULL);
	}
	buf = malloc((c_len - i + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (i < c_len)
		buf[b_len++] = ((char *)last->content)[++i];
	buf[b_len] = '\0';
	free(last->content);
	last->content = buf;
	if (((char *)last->content)[0] == '\0' && last->next == NULL)
	{
		clear_lst_to_stop(&(*list)->next, NULL);
		last = NULL;
	}
	else
		clear_lst_to_stop(&(*list)->next, last);
	return (last);
}

static t_list	*ft_after_nl(t_list **list)
{
	int		i;
	int		c_len;
	t_list	*last;

	last = (*list)->next;
	if (last == NULL || last->content == NULL)
		return (NULL);
	while (last)
	{
		i = -1;
		c_len = 0;
		if (last->content == NULL)
			break ;
		while (((char *)last->content)[c_len] != '\0')
		{
			if (i < 0 && ((char *)last->content)[c_len] == '\n')
				i = c_len;
			c_len++;
		}
		if (i >= 0)
			break ;
		last = last->next;
	}
	return (ft_leftovers(list, last, i, c_len));
}

// Copies list content into a string
static char	*ft_lst_to_string(t_list **list, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	t_list	*temp;

	temp = *list;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (temp)
	{
		j = 0;
		while ((char *)temp->content && ((char *)temp->content)[j])
		{
			str[i] = ((char *)temp->content)[j++];
			if (str[i++] == '\n')
				break ;
		}
		if (i > 0 && str[i - 1] == '\n')
			break ;
		temp = temp->next;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_build_list(t_list **list, int fd, ssize_t *bytes_read)
{
	t_list	*last;

	last = *list;
	if (last == NULL)
	{
		last = malloc(sizeof(t_list));
		if (last == NULL)
			return ;
		last->content = NULL;
		last->next = NULL;
		*list = last;
	}
	while (last)
	{
		ft_fd_to_lst(last, fd, bytes_read);
		if (*bytes_read <= 0)
			return ;
		last = last->next;
		if (ft_nl_check(last->content) >= 0)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*next_line;
	ssize_t			bytes_read;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	ft_build_list(&head, fd, &bytes_read);
	if (bytes_read < 0 || (bytes_read == 0 && head->next == NULL))
	{
		clear_lst_to_stop(&head, NULL);
		if (bytes_read < 0)
			return (NULL);
	}
	if (head)
	{
		next_line = ft_lst_to_string(&head, get_newline_len(&head));
		if (next_line == NULL || next_line[0] == '\0')
		{
			free(next_line);
			next_line = NULL;
		}
		ft_after_nl(&head);
		return (next_line);
	}
	return (NULL);
}
