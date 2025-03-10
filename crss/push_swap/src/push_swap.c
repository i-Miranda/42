/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 13:44:35 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_ps(t_stacks **stacks, int *rot_a, int *rot_b)
{
	*rot_a = 0;
	*rot_b = 0;
	pb(stacks);
	pb(stacks);
	if (*(int *)((*stacks)->b->next->content) <
			*(int *)((*stacks)->b->next->next->content))
		*rot_b = 1;
}

static void	loop_ps(t_stacks **stacks, int *rot_a, int *rot_b)
{
	while (check_list_sort(stacks) != ERR_NONE)
	{
		if (ft_lstsize((*stacks)->b) <= 0
			|| *(int *)(*stacks)->a->next->content < (*stacks)->mid_val)
		{
			if (*rot_b == 1)
			{
				rb(*stacks);
				*rot_b = 0;
			}
			pb(stacks);
		}
		else if (*(int *)(*stacks)->a->next->content
			> *(int *)(ft_lstlast((*stacks)->a)->content))
		{
			if (*rot_b == 1)
			{
				rr(*stacks);
				*rot_b = 0;
			}
			else
			{
				ra(*stacks);
				*rot_a = 0;
			}
		}
		else if (*(int *)(*stacks)->b->next->content
			> *(int *)(ft_lstlast((*stacks)->b)->content))
		{
			if (*rot_b == 1)
			{
				rb(*stacks);
				rot_b = 0;
			}
			rb(*stacks);
		}
	}
}

void	push_swap(t_stacks **stacks)
{
	int	waiting_rot_a;
	int	waiting_rot_b;

	init_ps(stacks, &waiting_rot_a, &waiting_rot_b);
	loop_ps(stacks, &waiting_rot_a, &waiting_rot_b);
}
