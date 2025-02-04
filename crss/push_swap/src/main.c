/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/04 11:04:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stacks *stacks;

	if (argc <= 1)
		return (1);
	stacks = NULL;
	if (init_stacks(&stacks) != 0)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (parse_arg(stacks, argv[i]) == 0)
			i++;
		else
			return (1);
	}
	push_swap(stacks);
	return (0);
}
