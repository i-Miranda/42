/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 02:20:06 by ivmirand         ###   ########.fr       */
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
	(*stacks)->min_val = INT_MIN;
	(*stacks)->max_val = INT_MAX;
	(*stacks)->a_size = 0;
	(*stacks)->b_size = 0;
	return (ERR_NONE);
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
