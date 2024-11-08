/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:20:03 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/01 14:25:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static t_list	*ft_after_nl(t_list **list)
{
	int		i;
	int		c_len;
	int		b_len;
	t_list	*last;
	char	*buf;

	b_len = 0;
	last = (*list)->next;
	if (last == NULL || last->content == NULL)
		return (NULL);
	while (last)
	{
		i = -1;
		c_len = 0;
		if (last->content == NULL)
			break ;
		while (last->content[c_len] != '\0')
		{
			if (i < 0 && last->content[c_len] == '\n')
				i = c_len;
			c_len++;
		}
		if (i >= 0)
			break ;
		last = last->next;
	}
	if (i < 0)
	{
		ft_lst_clear(list, NULL);
		return (NULL);
	}
	buf = malloc((c_len - i + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (i < c_len)
		buf[b_len++] = last->content[++i];
	buf[b_len] = '\0';
	free(last->content);
	last->content = buf;
	if (last->content[0] != '\0')
		ft_lst_clear(&(*list)->next, last);
	else
	{
		ft_lst_clear(&(*list)->next, NULL);
		last = NULL;
	}
	return (last);
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
		while (temp->content && temp->content[j] && i < len)
		{
			str[i] = temp->content[j++];
			if (str[i++] == '\n')
			{
				str[i] = '\0';
				return (str);
			}
		}
		temp = temp->next;
	}
	str[i] = '\0';
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
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
		if (last == NULL)
		{
			ft_lst_clear(&last, NULL);
			return ;
		}
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
	t_list			*temp;
	char			*next_line;
	ssize_t			bytes_read;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	ft_build_list(&head, fd, &bytes_read);
	if (bytes_read < 0)
	{
		ft_lst_clear(&head, NULL);
		return (NULL);
	}
	next_line = ft_lst_to_string(&head, get_newline_len(&head));
	if (bytes_read == 0 && head->next == NULL)
		ft_lst_clear(&head, NULL);
	if (head)
	{
		temp = ft_after_nl(&head);
		if (temp != NULL)
			head->next = temp;
	}
	return (next_line);
}
