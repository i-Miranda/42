/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:45:34 by ivan              #+#    #+#             */
/*   Updated: 2025/04/21 12:18:32 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	short_sort_2(t_stacks **stacks)
{
	if (a->head->value > a->head->next->value)
		sa(stacks);
		//exe_print_op(a, NULL, "sa");
}

/**
 * @brief Sorts a stack of size 3 in ascending order.
 * @param a The stack to be sorted.
 * @note There are 6 possible cases to consider:
 * 
 * - 1 2 3 (already sorted)

 * - 1 3 2 (first case)
 * 
 * - 2 1 3
 * 
 * - 2 3 1
 * 
 * - 3 1 2
 * 
 * - 3 2 1 (last case)
 */
static void	short_sort_3(t_stacks **stacks)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first < second && second > third && first < third)
	{
		sa(stacks);
		//exe_print_op(a, NULL, "sa");
		ra(stacks);
		//exe_print_op(a, NULL, "ra");
	}
	else if (first > second && second < third && first < third)
		sa(stacks);
		//exe_print_op(a, NULL, "sa");
	else if (first < second && second > third && first > third)
		rra(stacks);
		//exe_print_op(a, NULL, "rra");
	else if (first > second && second < third && first > third)
		ra(stacks);
		//exe_print_op(a, NULL, "ra");
	else if (first > second && second > third && first > third)
	{
		sa(stacks);
		//exe_print_op(a, NULL, "sa");
		rra(stacks);
		//exe_print_op(a, NULL, "rra");
	}
}

static void	short_sort_4(t_stacks **stacks)
{
	while (find_min_i(a) != 0)
	{
		if (find_min_i(a) <= 2)
			ra(stacks);
			//exe_print_op(a, NULL, "ra");
		else
			rra(stacks);
			//exe_print_op(a, NULL, "rra");
	}
	pb(stacks);
	//exe_print_op(a, b, "pb");
	sort3(stacks);
	pa(stacks);
	//exe_print_op(a, b, "pa");
}

static void	short_sort_5(t_stacks **stacks)
{
	while (find_min_i(a) != 0)
	{
		if (find_min_i(a) <= 2)
			ra(stacks);
			//exe_print_op(a, NULL, "ra");
		else
			rra(stacks);
			//exe_print_op(a, NULL, "rra");
	}
	pb(stacks);
	//exe_print_op(a, b, "pb");
	while (find_min_i(a) != 0)
	{
		if (find_min_i(a) <= 2)
			ra(stacks);
			//exe_print_op(a, NULL, "ra");
		else
			rra(stacks);
			//exe_print_op(a, NULL, "rra");
	}
	pb(stacks);
	//exe_print_op(a, b, "pb");
	sort3(stacks);
	pa(stacks);
	//exe_print_op(a, b, "pa");
	pa(stacks);
	//exe_print_op(a, b, "pa");
}

void	sort(t_stacks **stacks)
{
	if (stacks->a_size > 5 || stacks < 2)
	{
		k_sort1(a, b, size);
		k_sort2(a, b, size);
	}
	else
	{
		if (stacks->a_size == 2)
			short_sort_2(stacks);
		else if (stacks->a_size == 3)
			short_sort_3(stacks);
		else if (stacks->a_size == 4)
			short_sort_4(stacks);
		else if (stacks->a_size == 5)
			short_sort_5(stacks);
	}
}

