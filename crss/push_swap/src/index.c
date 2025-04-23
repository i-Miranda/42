/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:21:53 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 01:13:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indices(int *values, t_stack **stack)
{
	t_node	*tmp;
	int		i;

	tmp = (*stack)->first;
	while (tmp != NULL)
	{
		i = 0;
		while (i < (*stack)->size)
		{
			if (tmp->value == values[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static void	sort_values(int *values, int size)
{
	int	i;
	int	sorted_index;
	int	current_value;

	i = 1;
	while (i < size)
	{
		current_value = values[i];
		sorted_index = i - 1;
		while (sorted_index >= 0 && values[sorted_index] > current_value)
		{
			values[sorted_index + 1] = values[sorted_index];
			sorted_index--;
		}
		values[sorted_index + 1] = current_value;
		i++;
	}
}

int	get_indices(t_stack **stack)
{
	t_node	*tmp;
	int		i;
	int		*values;

	values = ft_calloc((*stack)->size, sizeof(int));
	if (values == NULL)
		return (1);
	tmp = (*stack)->first;
	i = 0;
	while (i < (*stack)->size && tmp != NULL)
	{
		values[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_values(values, (*stack)->size);
	assign_indices(values, stack);
	free(values);
	return (0);
}
