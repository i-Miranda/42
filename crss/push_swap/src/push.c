/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:53:34 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 14:00:56 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//get first element in from and puts on top of to
void	push(t_list **to, t_list **from)
{
	t_list	*temp;

	if (*from == NULL || *to == NULL)
		return ;
	if (ft_lstsize(*from) > 0)
	{
		temp = *from;
		temp->next = (*to)->next;
		(*from)->next = (*from)->next->next;
		*to = temp;
	}
}

void	pa(t_stacks **stacks)
{
	push(&(*stacks)->a, &(*stacks)->b);
	ft_printf("pa\n");
}

void	pb(t_stacks **stacks)
{
	push(&(*stacks)->b, &(*stacks)->a);
	ft_printf("pb\n");
}
