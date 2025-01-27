/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 12:41:15 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_list(t_list *a, char *arg)
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
	atoi = ft_atoi(arg);
	node = ft_lstnew(*atoi);
	ft_lstadd_front(a, node);
	return (0);
}
