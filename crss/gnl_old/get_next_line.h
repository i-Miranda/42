/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:17:45 by ivmirand          #+#    #+#             */
/*   Updated: 2024/10/18 17:16:49 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

// Utils
//list functions
t_list	**ft_lst_append(t_list **list, char *content);
void	ft_lst_to_string(t_list **list, char *str, int i);
void	ft_lst_clear(t_list **list);

void	ft_build_list(t_list **list, int fd);
int		check_newline(t_list **list);
char	*build_newline(t_list **list);
#endif
