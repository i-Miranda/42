/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>  	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:52:54 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/16 02:32:30 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*temp;

	if (*list == NULL || *list->next == NULL)
	if (ft_lstsize(*list) > 1)
	{
		temp = *head;
		*head = temp->next;
		temp->next = (*head)->next->next;
		(*head)->next->next = temp;
	}
}

void	sa(t_stacks *stacks)
{
	swap(&(stacks->a));
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&(stacks->b));
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	ft_printf("ss\n");
}
