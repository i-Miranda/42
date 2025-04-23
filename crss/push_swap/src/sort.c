/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:45:34 by ivan              #+#    #+#             */
/*   Updated: 2025/04/22 18:16:29 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_i(t_stack *stack)
{
	int		min_val;
	t_node	*current;
	int		min_index;
	int		i;

	if (stack == NULL || stack->first == NULL)
		return (-1);
	min_val = stack->first->value;
	current = stack->first;
	min_index = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	ps_sort_2(t_stacks **stacks)
{
	int	first;
	int	second;

	first = (*stacks)->a->first->value;
	second = (*stacks)->a->first->next->value;
	if (first > second)
		sa(stacks);
}

void	ps_sort_3(t_stacks **stacks)
{
	int	first;
	int	second;
	int	third;

	first = (*stacks)->a->first->value;
	second = (*stacks)->a->first->next->value;
	third = (*stacks)->a->first->next->next->value;
	if (first > second && first > third)
		ra(stacks);
	else if (second > first && second > third)
		rra(stacks);
	if (first > second)
		sa(stacks);
}

void	ps_sort_4(t_stacks **stacks)
{
	while (find_min_i((*stacks)->a) != 0)
	{
		if (find_min_i((*stacks)->a) <= 2)
			ra(stacks);
		else
			rra(stacks);
	}
	pb(stacks);
	ps_sort_3(stacks);
	pa(stacks);
}

void	ps_sort_5(t_stacks **stacks)
{
	while (find_min_i((*stacks)->a) != 0)
	{
		if (find_min_i((*stacks)->a) <= 2)
			ra(stacks);
		else
			rra(stacks);
	}
	pb(stacks);
	ps_sort_4(stacks);
	pa(stacks);
}
