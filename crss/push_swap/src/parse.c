/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:52:33 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 23:45:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_duplicate_values(t_stacks *stacks)
{
	t_node	*ref;
	t_node	*comp;

	ref = stacks->a->first;
	comp = stacks->a->first->next;
	while (ref->next != NULL)
	{
		while(comp->next != NULL)
		{
			if (comp->value == ref->value)
				return (1);
			comp = comp->next;
		}
		ref = ref->next;
	}
	return (0);
}

static int	atol_args(t_stacks **stacks, char **args)
{
	long	atol;
	t_node	*node;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		atol = ft_atol(args[i]);
		if (atol < INT_MIN || atol > INT_MAX)
			return (-1);
		node = init_node((int)atol, (*stacks)->a);
		if (node == NULL)
			return (-2);
		if (atol < (*stacks)->min_val)
			(*stacks)->min_val = (int)atol;
		if (atol > (*stacks)->max_val)
			(*stacks)->max_val = (int)atol;
		i++;
	}
	(*stacks)->mid_val = ((*stacks)->min_val + (*stacks)->max_val) / 2;
	return (0);
}

int	parse_arg(t_stacks **stacks, char *arg)
{
	int		i;
	int		error;
	char	**split_array;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0 && arg[i] != ' ')
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	split_array = ft_split(arg, ' ');
	error = atol_args(stacks, split_array);
	ft_free_split(split_array);
	return (error);
}
