/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>  	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:52:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 23:37:17 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*temp;

	if (ft_lstsize(*list) > 1)
	{
		temp = (*list)->next->next;
		(*list)->next->next = (*list)->next;
		(*list)->next = temp;
	}
}

void	sa(t_stacks *stacks)
{
	swap(&(stacks->a));
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&(stacks->b));
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	ft_printf("ss\n");
}
