/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:38:24 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 10:32:06 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node *next;

	next = NULL;
	if (stack->first != NULL)
	{
		while (stack->first != NULL)
		{
			next = stack->first->next;
			free(stack->first);
			stack->first = next;
		}
	}
	free(stack);
}

int	free_stacks(t_stacks *stacks, int error)
{
	if (stacks->a != NULL)
		free_stack(stacks->a);
	if (stacks->a != NULL)
		free_stack(stacks->b);
	free(stacks);
	return (error);	
}


int	init_stack(t_stack *stack, t_stacks *parent)
{
	stack = ft_calloc(1 + 1, sizeof(t_stack));
	if ((*stacks)->a == NULL)
		return (1);
	stack->parent = parent;
	stack->first = NULL;
	stack->last = NULL;
	size = 0;	
	return (0);
}

int	init_stacks(t_stacks **stacks)
{
	*stacks = ft_calloc(1 + 1, sizeof(t_stacks));
	if (*stacks == NULL)
		return (1);
	if (init_stack(stacks->a) != 0)	
		return (free_stacks(*stacks), 2);
	if (init_stack(stacks->b) != 0)	
		return (free_stacks(*stacks), 3);
	(*stacks)->a_size = &(*stacks)->a->size;
	(*stacks)->b_size = &(*stacks)->b->size;
	return (0);
}
