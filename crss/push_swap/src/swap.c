/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>  	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:52:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 10:43:00 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_node	*temp;

	if (*stack == NULL || (*stack)->first == NULL)
		return ;
	if ((*stack->size > 1)
	{
		temp = (*stack)->first;
		(*stack)->first = temp->next;
		(*stack)->first->prev = NULL;
		temp->prev = (*stack)->first;
		temp->next = (*stack)->first->next;
		(*stack)->first->next = temp->next->next;
		(*stack)->first->index--;
		temp->next->index++;
		(*head)->next->next = temp;
	}
}

void	sa(t_stacks *stacks)
{
	swap(&stacks->a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->b);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->a);
	swap(&stacks->b);
	ft_printf("ss\n");
}
