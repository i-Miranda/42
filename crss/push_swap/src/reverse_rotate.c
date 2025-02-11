/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 16:44:35 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a down one position so the last element is now
//the first.
void	reverse_rotate(t_list **list)
{
	t_list	*last;
	t_list	*seclast;

	last = (*list)->next;
	while (last->next)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = (*list)->next;
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(&(stacks->a));
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&(stacks->b));
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&(stacks->a));
	reverse_rotate(&(stacks->b));
	ft_printf("rrr\n");
}
