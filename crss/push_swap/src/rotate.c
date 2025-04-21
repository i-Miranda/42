/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:09 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 11:45:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a up one position so the first element is now
//the last.
void	rotate(t_stack **stack)
{
	t_node	*temp;

	if (*stack == NULL || (*stack)->first == NULL)
		return ;
	temp = (*stack)->first;
	(*stack)->first = temp->next;
	(*stack)->first->prev = NULL;
	node_to_bottom(temp, *stack);
	temp = (*stack)->first;
	while (temp != (*stack)->last)
	{
		temp->index--;
		temp = temp->next;
	}
}

void	ra(t_stacks *stacks)
{
	rotate(&stacks->a);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->b);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	ft_printf("rr\n");
}
