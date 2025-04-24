/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:45:34 by ivan              #+#    #+#             */
/*   Updated: 2025/04/24 11:04:32 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		min_val;
	int		min_index;
	int		i;

	if (stack == NULL || stack->first == NULL)
		return (-1);
	current = stack->first;
	min_val = current->index;
	min_index = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->index < min_val)
		{
			min_val = current->index;
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
	if (first < second && second < third)
		return ;
	if (first > second && second < third && first < third)
		sa(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first > second && second < third && first > third)
		ra(stacks);
	else if (first < second && second > third && first < third)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first < second && second > third && first > third)
		rra(stacks);
}

void	ps_sort_4(t_stacks **stacks)
{
	while (find_min_index((*stacks)->a) != 0)
	{
		if (find_min_index((*stacks)->a) <= 2)
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
	while (find_min_index((*stacks)->a) != 0)
	{
		if (find_min_index((*stacks)->a) <= 2)
			ra(stacks);
		else
			rra(stacks);
	}
	pb(stacks);
	while (find_min_index((*stacks)->a) != 0)
	{
		if (find_min_index((*stacks)->a) <= 2)
			ra(stacks);
		else
			rra(stacks);
	}
	pb(stacks);
	ps_sort_3(stacks);
	pa(stacks);
	pa(stacks);
}
