/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 11:48:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a down one position so the last element is now
//the first.
void	reverse_rotate(t_stack **stack)
{
	t_node	*temp;

	if (*stack == NULL || (*stack)->last == NULL)
		return ;
	temp = (*stack)->last;
	(*stack)->last = temp->prev;
	(*stack)->last->next = NULL;
	node_to_top(temp, *stack);
	temp = (*stack)->first;
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
