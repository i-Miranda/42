/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:38:24 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 06:45:01 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (stack && *stack)
	{
		current = (*stack)->first;
		while (current != NULL)
		{
			next = current->next;
			free(current);
			current = next;
		}
		free(*stack);
		*stack = NULL;
	}
}

static int	init_stack(t_stack **stack)
{
	*stack = ft_calloc(1 + 1, sizeof(t_stack));
	if (stack == NULL)
		return (1);
	(*stack)->first = NULL;
	(*stack)->last = NULL;
	(*stack)->size = 0;
	(*stack)->max_val = 0;
	return (0);
}

t_node	*init_node(int value, t_stack **stack)
{
	t_node	*node;
	t_node	*temp;

	if (stack == NULL || *stack == NULL)
		return (NULL);
	node = ft_calloc(1 + 1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->value = value;
	if ((*stack)->first == NULL)
		(*stack)->first = node;
	else
	{
		temp = (*stack)->first;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
		node->prev = temp;
	}
	(*stack)->last = node;
	(*stack)->size++;
	return (node);
}

int	free_stacks(t_stacks **stacks, int error)
{
	if ((*stacks)->a != NULL)
		free_stack(&(*stacks)->a);
	if ((*stacks)->b != NULL)
		free_stack(&(*stacks)->b);
	free(*stacks);
	*stacks = NULL;
	if (error != 0)
		ft_putstr_fd("Error\n", 2);
	return (error);
}

int	init_stacks(t_stacks **stacks)
{
	*stacks = ft_calloc(1 + 1, sizeof(t_stacks));
	if (*stacks == NULL)
		return (1);
	if (init_stack(&(*stacks)->a) != 0)
		return (free_stacks(stacks, 2));
	if (init_stack(&(*stacks)->b) != 0)
		return (free_stacks(stacks, 3));
	return (0);
}
