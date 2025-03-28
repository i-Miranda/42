/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:09 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/26 08:15:54 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a up one position so the first element is now
//the last.
void	rotate(t_list **list)
{
	t_list	*temp;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	temp = *list;
	(*list) = temp->next;
	temp->next = NULL;
	ft_lstadd_back(list, temp);
}

void	ra(t_stacks *stacks)
{
	rotate(&(stacks->a));
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&(stacks->b));
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	rotate(&(stacks->a));
	rotate(&(stacks->b));
	ft_printf("rr\n");
}
