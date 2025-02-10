/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:53:34 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/10 15:35:58 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get first element in from and puts on top of to
void	push(t_list **to, t_list **from)
{
	t_list	*temp;

	if (ft_lstsize(*from) > 0)
	{
		temp = (*to)->next;
		(*to)->next = (*from)->next;
		(*from)->next = (*from)->next->next;
		(*to)->next->next = temp;
	}
}

void	pa(t_stacks *stacks)
{
	push(&(stacks->a),&(stacks->b));
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	push(&(stacks->b), &(stacks->a));
	ft_printf("pb\n");
}
