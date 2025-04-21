/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 10:08:35 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 10:20:49 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// probably should return int here
t_node	*init_node(int value, t_stack *stack)
{
	t_node *node;
	t_node *temp;

	if (stack == NULL)
		return (NULL);
	node = ft_calloc(1 + 1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->head = stack;
	node->prev = NULL;
	node->value = value;
	if (stack->first == NULL)
		stack->first = node;
	else 
	{
		temp = stack->first;
		while (temp->next != NULL)
		{
			temp->next->prev = temp;
			temp = temp->next;	
		}
		temp->next = node;
	}
	stack->last = node;
	node->index = stack->size++;
	return (node);
}

void	node_to_top(t_node *node, t_stack *stack)
{
	t_node *temp;
	
	if (node == NULL || stack == NULL)
		return ;
	temp = stack->first;
	while (temp->next != NULL)
	{
		temp->index++;
		temp = temp->next;
	}
	node->index = 0;	
	node->prev = NULL;
	node->next = stack->first;
	stack->first = node;
}

void	node_to_bottom(t_node *node, t_stack *stack)
{
	if (node == NULL || stack == NULL)
		return ;
	node->index = stack->size;
	node->next = NULL;
	node->prev = stack->last;
	stack->last = node;
}
