/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:53:34 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 10:29:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **to, t_stack **from)
{
	t_list	*temp;

	if (*from == NULL || *to == NULL)
		return ;
	if ((*from)->size > 0)
	{
		temp = (*from)->first->next;
		node_to_top((*from)->first, *to);
		(*to)->size++;
		temp->prev = NULL;
		(*from)->first = temp;	
		while (temp->next != NULL)
		{
			temp->index--;
			temp = temp->next;
		}
		(*from)->size--;
	}
}

void	pa(t_stacks *stacks)
{
	push(&stacks->a, &stacks->b);
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{
	push(&stacks->b, &stacks->a);
	ft_printf("pb\n");
}
