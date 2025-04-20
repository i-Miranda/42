/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:35:05 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/19 12:06:21 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	loading_fdf(int tick, char *msg)
{
	if (msg != NULL)
	{
		if (tick % 4 == 0)
			ft_printf("%s                            \r", msg);
		else if (tick % 4 == 1)
			ft_printf("%s.                           \r", msg);
		else if (tick % 4 == 2)
			ft_printf("%s..                          \r", msg);
		else if (tick % 4 == 3)
			ft_printf("%s...                         \r", msg);
	}
	else
	{
		if (tick % 4 == 0)
			ft_printf("Loading                       \r");
		else if (tick % 4 == 1)
			ft_printf("Loading.                      \r");
		else if (tick % 4 == 2)
			ft_printf("Loading..                     \r");
		else if (tick % 4 == 3)
			ft_printf("Loading...                    \r");
	}
}
