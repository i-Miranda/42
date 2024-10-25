/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:19:08 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/21 16:44:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lst_last(t_list *list)
{
	t_list	*last_node;

	last_node = list;
	if (last_node == NULL)
		return (NULL);
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

// Copies list content into a string
char	*ft_lst_to_string(t_list *list, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (list)
	{
		if (list->content)
		{
			j = 0;
			while (list->content[j] != '\0')
				str[i++] = list->content[j++];
		}
		list = list->next;
	}
	str[i] = '\0';
	printf("str is %s : ft_lst_to_string\n", str);
	return (str);
}

// Clears list, if a stop is added clears list until stop
void	ft_lst_clear(t_list **list, t_list *stop)
{
	t_list	*current;
	t_list	*next;

	current = *list;
	while (current != stop)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	if (stop == NULL)
	{
		*list = NULL;
	}
	else
		*list = current;
}

int	ft_nl_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		//printf("str is NULL. returning -1: ft_nl_check\n");
		return (-1);
	}
	while (i < BUFFER_SIZE)
	{
		if (str[i++] == '\n')
		{
			printf("newline found. returning i(%d): ft_nl_check\n", i);
			return (i);
		}
	}
	printf("newline not found. returning 0: ft_nl_check\n");
	return (0);
}

ssize_t	ft_fd_to_lst(t_list *list, int fd)
{
	char	*buf;
	ssize_t	bytes_read;
	t_list	*new;

	bytes_read = -1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (bytes_read);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		//printf("bytes_read <= 0. Freeing buf. : ft_fd_to_last\n");
		free(buf);
		return (bytes_read);
	}
	buf[bytes_read] = '\0';
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buf);
		return (bytes_read);
	}
	new->content = buf;
	new->next = NULL;
	if (list != NULL)
		list->next = new;
	else
	{
		free(new);
		free(buf);
		return (-1);
	}
	return (bytes_read);

}
