/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:53:34 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 12:39:18 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get first element in from and puts on top of to
t_list	*push(t_list *to, t_list *from)
{
	t_list	*to_head;

	if (ft_lstsize(from) > 0)
	{
		from->next = *to;
		to_head = from;
	}
	return (to_head);
}

t_list	*pa(t_stacks *stacks)
{
	t_list	*a_head;

	a_head = push(stacks->a,stacks->b);
	ft_printf("pa\n");
	return (a_head);
}

t_list	*pb(t_stacks *stacks)
{
	t_list	*b_head;

	b_head = push(stacks->b, stacks->a);
kft_printf("pb\n");
	return (b_head);
}
