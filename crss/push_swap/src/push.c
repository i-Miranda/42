/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:53:34 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/23 19:28:47 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **to, t_stack **from)
{
	t_node	*tmp;

	if (from == NULL || *from == NULL || (*from)->first == NULL)
		return (1);
	tmp = (*from)->first;
	(*from)->first = (*from)->first->next;
	if ((*from)->first != NULL)
		(*from)->first->prev = NULL;
	else
		(*from)->last = NULL;
	(*from)->size--;
	tmp->prev = NULL;
	tmp->next = (*to)->first;
	if ((*to)->first != NULL)
		(*to)->first->prev = tmp;
	else
		(*to)->last = tmp;
	(*to)->first = tmp;
	(*to)->size++;
	return (0);
}

void	pa(t_stacks **stacks)
{
	int	error;

	error = push(&(*stacks)->a, &(*stacks)->b);
	ft_printf("pa\n");
	if (error != 0)
		exit(EXIT_FAILURE);
}

void	pb(t_stacks **stacks)
{
	int	error;

	error = push(&(*stacks)->b, &(*stacks)->a);
	ft_printf("pb\n");
	if (error != 0)
		exit(EXIT_FAILURE);
}
