/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 12:34:53 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_stacks *stacks;

	if (argc <= 1)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		if (build_list(a, argv[i]) == 0)
			i++;
		else
			return (1);
	}
	push_swap(a, b);
	return (0);
}
