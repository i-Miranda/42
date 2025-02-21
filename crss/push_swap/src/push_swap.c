/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/21 11:20:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stacks **stacks)
{
	//Send two numbers to and place larger number on top
	pb((*stacks));
	pb((*stacks));

	if (*(int *)((*stacks)->b->next->content) < 
			*(int *)((*stacks)->b->next->next->content))
		rb((*stacks));

	while (check_list_sort(stacks) != ERR_NONE)
	{
		if (ft_lstsize((*stacks)->b) <= 0
				|| *(int *)(*stacks)->a->next->content < (*stacks)->mid_val)
			pb((*stacks));
		else if (*(int *)(*stacks)->a->next->content 
				> *(int *)(ft_lstlast((*stacks)->a)->content))
			ra((*stacks));
		else if (*(int *)(*stacks)->b->next->content 
				> *(int *)(ft_lstlast((*stacks)->b)->content))
			rb((*stacks));
	}
}
