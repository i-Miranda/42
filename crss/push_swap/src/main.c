/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/20 23:42:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	t_stacks	*stacks;

	if (argc <= 1)
		return (1);
	stacks = NULL;
	if (init_stacks(&stacks) != 0)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (parse_arg(&stacks, argv[i]) == 0)
			i++;
		else
			return (free_stacks(stacks, 1));
	}
	if (find_duplicate_values(stacks) != 1)
		return (free_stacks(stacks, 1));
	push_swap(&stacks);
	return (0);
}
