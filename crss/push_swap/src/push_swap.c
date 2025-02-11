/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/11 23:34:58 by ivan             ###   ########.fr       */
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

	while (ft_lstsize(stacks->a) > 3)
	{
		//set target nodes in stack b for the nodes in stack a
		//calculate the lowest possible move to push
		//push the lowest
	}
	if (ft_lstsize(stacks->a) == 3)
		sort_short_stack(&stacks);
	while (ft_lstsize(stacks->b) > 3)
	{
		//set target nodes in stack a for the nodes in stack b
		//calculate the lowest possible move to push
		//push the lowest
	}
	if (*(int *)(stacks->b->next->content) < 
			*(int *)(stacks->b->next->next->content))
		rb(stacks);

	while (isSorted == 0)
	{
		if (ft_lstsize(stacks->b) <= 0
				|| *(int *)stacks->a->next->content < *stacks->mid_val)
			pb(stacks);
		else if (*(int *)stacks->a->next->content 
				> *(int *)(ft_lstlast(stacks->a)->content))
			ra(stacks);
		else if (*(int *)stacks->b->next->content 
				> *(int *)(ft_lstlast(stacks->b)->content))
			rb(stacks);
		else if (*(int *)stacks->a->next->content == *stacks->min_val
				|| *(int *)stacks->b->next->content == *stacks->min_val)
			isSorted = 1;
	}
}
