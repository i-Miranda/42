/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 07:25:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_sort(t_stacks **stacks)
{
	t_node	*current;

	if ((*stacks)->b->size != 0)
		return (1);
	if ((*stacks)->a->size <= 1)
		return (0);
	current = (*stacks)->a->first;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	push_swap(t_stacks **stacks)
{
	if ((*stacks)->a->size > 5 || (*stacks)->a->size < 2)
	{
		k_sort_start(stacks);
		k_sort_end(stacks);
	}
	else
	{
		if ((*stacks)->a->size == 2)
			ps_sort_2(stacks);
		else if ((*stacks)->a->size == 3)
			ps_sort_3(stacks);
		else if ((*stacks)->a->size == 4)
			ps_sort_4(stacks);
		else if ((*stacks)->a->size == 5)
			ps_sort_5(stacks);
	}
}

int	main(int argc, char *argv[])
{
	int			i;
	t_stacks	*stacks;

	stacks = NULL;
	i = 1;
	if (argc <= 1 || init_stacks(&stacks) != 0)
		return (1);
	while (i < argc)
	{
		if (parse_arg(&stacks, argv[i]) == 0)
			i++;
		else
			return (free_stacks(&stacks, 1));
	}
	if (find_duplicate_values(stacks) == 0)
		return (free_stacks(&stacks, 1));
	if (get_indices(&stacks->a) != 0)
		return (free_stacks(&stacks, 1));
	while (check_sort(&stacks) != 0)
		push_swap(&stacks);
	return (free_stacks(&stacks, 0));
}
