/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 12:42:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a down one position so the last element is now
//the first.
t_list	*reverse_rotate(t_list *list)
{
	t_list	*head;
	t_list	*last;

	head = ft_lstlast(list);
	head->next = *list;
	last = ft_lstlast(head);
	free(last->next);
}

t_list	*rra(t_list *a)
{
	t_list	*a_head;

	reverse_rotate(a);
	ft_printf("rra\n");
	return (a_head);
}

t_list	*rrb(t_list *b)
{
	t_list	*b_head;

	reverse_rotate(b);
	ft_printf("rrb\n");
	return (b_head);
}

void	rrr(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
