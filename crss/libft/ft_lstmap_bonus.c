/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:05:51 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:11:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	if (lst == NULL)
		return ;
	while (lst != null)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
			free(node);
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}
