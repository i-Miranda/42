/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/28 13:45:55 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the algorithm
void	push_swap(t_stacks *stacks)
{
	int	isSorted;

	isSorted = 0;
	while (isSorted == 0)
	{
		if (ft_lstsize(stacks->b) <= 0 ||
				stacks->a->next->content < stacks->midVal)
			pb(stacks);
		else if (stacks->a->next->content > ft_lstlast(stacks->a)->content)
			ra(stacks);
		if (stacks->b->next->content > ft_lstlast(stacks->b)->content)
			rb(stacks);
	}
}
