/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/23 13:41:15 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack, char *cmd)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->first == NULL
		|| (*stack)->size < 2)
		return ;
	tmp = (*stack)->last;
	(*stack)->last = tmp->prev;
	(*stack)->last->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*stack)->first;
	if ((*stack)->first != NULL)
		(*stack)->first->prev = tmp;
	(*stack)->first = tmp;
	if (cmd != NULL)
		ft_printf("%s\n", cmd);
}

void	rra(t_stacks **stacks)
{
	reverse_rotate(&(*stacks)->a, "rra");
}

void	rrb(t_stacks **stacks)
{
	reverse_rotate(&(*stacks)->b, "rrb");
}

void	rrr(t_stacks **stacks)
{
	reverse_rotate(&(*stacks)->a, NULL);
	reverse_rotate(&(*stacks)->b, NULL);
	ft_printf("rrr\n");
}
