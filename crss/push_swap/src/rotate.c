/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:09 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 12:43:30 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a up one position so the first element is now
//the last.
t_list	*rotate(t_list *list)
{
	t_list	*head;
	t_list	*last;

	head = list->next;
	ft_lstadd_back(list, list);
	last = ft_lstlast(list);
	free(last->next);
	return (head);
}

t_list	*ra(t_list *a)
{
	t_list	*a_head;

	a_head = rotate(a);
	ft_printf("ra\n");
	return (a_head);
}

t_list	*rb(t_list *b)
{
	t_list	*b_head;

	a_head = rotate(b);
	ft_printf("rb\n");
	return (b_head);
}

void	rr(t_list *a, t_list *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
