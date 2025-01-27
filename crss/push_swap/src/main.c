/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:22:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 10:23:08 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	t_list *a;
	t_list *b;

	if (argc <= 1)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		build_list(a, argv[i]);		
		i++;
	}
}
