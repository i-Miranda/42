/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/28 12:50:16 by ivmirand         ###   ########.fr       */
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
	stacks->minVal = malloc(sizeof(int));
	if (stacks->minVal == NULL)
		return (4);
	stacks->midVal = malloc(sizeof(int));
	if (stacks->midVal == NULL)
		return (5);
	stacks->maxVal = malloc(sizeof(int));
	if (stacks->maxVal == NULL)
		return (6);
	return (0);
}

int	build_list(t_stacks *stacks, char *arg)
{
	int		i;
	int		atoi;
	t_list	*node;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	node = ft_lstnew(*atoi);
	if (node == NULL)
		return (2);
	atoi = ft_atoi(arg);
	if (stacks->minVal == NULL || atoi < stacks->minVal)
		stacks->minVal = atoi;
	if (stacks->maxVal == NULL || atoi > stacks->maxVal)
		stacks->maxVal = atoi;
	stacks->midVal = (stacks->minVal + stacks->maxVal)/2;
	ft_lstadd_front(stacks->a, node);
	return (0);
}
