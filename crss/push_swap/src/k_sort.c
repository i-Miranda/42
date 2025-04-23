/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:23:45 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 01:07:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack **stack)
{
	int		max_index;
	t_node	*tmp;

	tmp = (*stack)->first;
	max_index = tmp->index;
	while (tmp != NULL)
	{
		if (max_index < tmp->index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

static	int	get_sqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	fastest_rot(t_node *node, int index)
{
	int	count;

	count = 0;
	while (node)
	{
		if (node->index == index)
			return (count);
		node = node->next;
		count++;
	}
	return (-1);
}

void	k_sort_start(t_stacks **stacks)
{
	int	i;
	int	rng;

	i = 0;
	rng = get_sqrt((*stacks)->a->size) * 1.4;
	while ((*stacks)->a->size > 0)
	{
		if ((*stacks)->a->first->index <= i)
		{
			pb(stacks);
			i++;
		}
		else if ((*stacks)->a->first->index <= i + rng)
		{
			pb(stacks);
			if ((*stacks)->b->size > 2 && (*stacks)->a->first->index > i + rng)
				rr(stacks);
			else if ((*stacks)->b->size > 2)
				rb(stacks);
			i++;
		}
		else
			ra(stacks);
	}
}

void	k_sort_end(t_stacks **stacks)
{
	int	rb_count;
	int	rrb_count;
	int	max_index;

	while ((*stacks)->b->size > 0)
	{
		max_index = find_max_index(&(*stacks)->b);
		rb_count = fastest_rot((*stacks)->b->first, max_index);
		rrb_count = (*stacks)->b->size - rb_count;
		if (rb_count <= rrb_count)
		{
			while ((*stacks)->b->first->index != max_index)
				rb(stacks);
		}
		else
		{
			while ((*stacks)->b->first->index != max_index)
				rrb(stacks);
		}
		pa(stacks);
	}
}
