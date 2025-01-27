/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 10:24:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_list(t_list *a, char *arg)
{
	int	i;
	int	atoi;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_isdigit(arg[i]) == 1)
		{
			//printf Error
			return (1);
		}
		i++;
	}
	atoi = ft_atoi(arg);
	//add atoi to list a
	return (0);
}
