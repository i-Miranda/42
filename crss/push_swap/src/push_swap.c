/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/28 17:46:06 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the algorithm
void	push_swap(t_stacks *stacks)
{
	int	isSorted;

	isSorted = 0;
	
	//Send two numbers to and place larger number on top
	pb(stacks);
	pb(stacks);
	if (stacks->b->next->content < stacks->b->next->next->content)
		rb(stacks);

	while (isSorted == 0)
	{
		if (ft_lstsize(stacks->b) <= 0 ||
				stacks->a->next->content < stacks->mid_val)
			pb(stacks);
		else if (*(stacks->a->next->content) > (*ft_lstlast(stacks->a)->content))
			ra(stacks);
		if (*(stacks->b->next->content) > *(ft_lstlast(stacks->b)->content))
			rb(stacks);
	

		if (stacks->a->next->content == stacks->min_val)
			isSorted = 1;
	}
}
