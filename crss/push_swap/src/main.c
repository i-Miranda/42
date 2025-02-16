/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 02:18:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stacks *stacks;

	if (argc <= 1)
		return (ERR_GNRL);
	stacks = NULL;
	if (init_stacks(&stacks) != ERR_NONE)
		return (ERR_GNRL);
	i = 1;
	while (i < argc)
	{
		if (parse_arg(stacks, argv[i]) == ERR_NONE)
			i++;
		else
			return (ERR_GNRL);
	}
	push_swap(stacks);
	return (ERR_NONE);
}
