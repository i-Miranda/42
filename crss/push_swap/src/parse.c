/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:52:33 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 11:36:01 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_invalid_split(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if ((j == 0 && (split[i][j] == '+' || split[i][j] == '-')
				&& !ft_isdigit(split[i][j + 1]))
				|| (j > 0 && (split[i][j] == '+' || split[i][j] == '-')))
			{
				ft_free_split(split);
				return (1);
			}
			j++;
		}
		i++;
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
		node = init_node((int)atol, &(*stacks)->a);
		if (node == NULL)
			return (-2);
		i++;
	}
	return (0);
}

int	find_duplicate_values(t_stacks *stacks)
{
	t_node	*ref;
	t_node	*comp;

	ref = stacks->a->first;
	while (ref->next != NULL)
	{
		comp = ref->next;
		while (comp != NULL)
		{
			if (comp->value == ref->value)
				return (0);
			comp = comp->next;
		}
		ref = ref->next;
	}
	return (1);
}

int	parse_arg(t_stacks **stacks, char *arg)
{
	int		i;
	int		error;
	char	**split_array;

	i = 0;
	if (arg == NULL || arg[0] == '\0')
		return (1);
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 0 && arg[i] != ' ' && arg[i] != '-'
			&& arg[i] != '+')
			return (1);
		i++;
	}
	split_array = ft_split(arg, ' ');
	if (find_invalid_split(split_array) == 1)
		return (1);
	i = 0;
	error = atol_args(stacks, split_array);
	ft_free_split(split_array);
	return (error);
}
