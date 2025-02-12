/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/12 08:37:52 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stacks(t_stacks **stacks)
{
	*stacks = malloc(sizeof(t_stacks));
	if (*stacks == NULL)
		return (1);
	(*stacks)->a = malloc(sizeof(t_list));
	if ((*stacks)->a == NULL)
		return (2);
	(*stacks)->b = malloc(sizeof(t_list));
	if ((*stacks)->b == NULL)
		return (3);
	(*stacks)->min_val = (int *)malloc(sizeof(int));
	if ((*stacks)->min_val == NULL)
		return (4);
	(*stacks)->mid_val = (int *)malloc(sizeof(int));
	if ((*stacks)->mid_val == NULL)
		return (5);
	(*stacks)->max_val = (int *)malloc(sizeof(int));
	if ((*stacks)->max_val == NULL)
		return (6);
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
