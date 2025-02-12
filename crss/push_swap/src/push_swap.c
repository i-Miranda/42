/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/12 20:21:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int sort_and_push(t_list **to, t_list **from)
//{
//	if (ft_lstsize(stacks->b) <= 3)
//		return (-1);
//	while (ft_lstsize(stacks->b) > 3)
//	{
//		//set target nodes in stack a for the nodes in stack b
//		//calculate the lowest possible move to push
//		//push the lowest
//	}
//}
//
//static int sort_and_push_b(t_stacks *stacks)
//{
//}
//
//static int sort_and_push_a(t_stacks *stacks)
//{
//	if (ft_lstsize(stacks->a) <= 3)
//		return (-1);
//	while (ft_lstsize(stacks->a) > 3)
//	{
//		//set target nodes in stack b for the nodes in stack a
//		//calculate the lowest possible move to push
//		//push the lowest
//	}
//}

void	push_swap(t_stacks *stacks)
{
	int	isSorted;

	isSorted = 0;
	//Send two numbers to and place larger number on top
	pb(stacks);
	pb(stacks);

	//if (sort_and_push_a(t_stacks *stacks) == 0 && ft_lstsize(stacks->a) == 3)
	//	sort_short_stack(&stacks);
	//if (sort_and_push_b(t_stack *stacks) == 0  && ft_lstsize(stacks->b) == 3)
	//	sort_short_stack(&stacks);

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
