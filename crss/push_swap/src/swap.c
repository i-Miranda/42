/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>  	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:52:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/23 13:40:56 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack, char *cmd)
{
	t_node	*first;
	t_node	*second;

	if (stack == NULL || *stack == NULL || (*stack)->first == NULL
		|| (*stack)->size < 2)
		return ;
	first = (*stack)->first;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	else
		(*stack)->last = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*stack)->first = second;
	if (cmd != NULL)
		ft_printf("%s\n", cmd);
}

void	sa(t_stacks **stacks)
{
	swap(&(*stacks)->a, "sa");
}

void	sb(t_stacks **stacks)
{
	swap(&(*stacks)->b, "sb");
}

void	ss(t_stacks **stacks)
{
	swap(&(*stacks)->a, NULL);
	swap(&(*stacks)->b, NULL);
	ft_printf("ss\n");
}
