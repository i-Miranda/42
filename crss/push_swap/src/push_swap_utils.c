/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/28 17:20:03 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stacks *stacks)
{
	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (1);
	stacks->a = malloc(sizeof(t_list));
	if (stacks->a == NULL)
		return (2);
	stacks->b = malloc(sizeof(t_list));
	if (stacks->b == NULL)
		return (3);
	stacks->min_val = (int *)malloc(sizeof(int));
	if (stacks->min_val == NULL)
		return (4);
	stacks->mid_val = (int *)malloc(sizeof(int));
	if (stacks->mid_val == NULL)
		return (5);
	stacks->max_val = (int *)malloc(sizeof(int));
	if (stacks->max_val == NULL)
		return (6);
	return (0);
}

int	parse_arg(t_stacks *stacks, char *arg)
{
	int		i;
	int		bl_result;
	char	**split_array;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 1 && arg[i] != ' ')
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	split_array = ft_split(arg, ' ');
	bl_result = atoi_args(stacks, split_array);
	free_split(split_array);
	if (bl_result != 0)
		return (2);
	return (0);
}

int	atoi_args(t_stacks *stacks, char **args)
{
	int		*atoi;
	t_list	*node;

	atoi = malloc(1 * sizeof(int));
	if (atoi == NULL)
		return (-1);
	*atoi = ft_atoi(*args);
	node = ft_lstnew(atoi);
	if (node == NULL)
		return (1);
	if ((stacks->min_val) == NULL || *atoi < *(stacks->min_val))
		stacks->min_val = atoi;
	if ((stacks->max_val) == NULL || *atoi > *(stacks->max_val))
		stacks->max_val = atoi;
	*(stacks->mid_val) = (*(stacks->min_val) + *(stacks->max_val)/2);
	ft_lstadd_front(&(stacks->a), node);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
			i++;
		while (i >= 0)
		{
			free(split[i]);
			i--;
		}
		free(split);
	}
}
