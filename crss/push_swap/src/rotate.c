/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:09 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/23 19:27:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack, char *cmd)
{
	t_node	*tmp;

	if (stack == NULL || *stack == NULL || (*stack)->first == NULL
		|| (*stack)->size < 2)
		return (1);
	tmp = (*stack)->first;
	(*stack)->first = tmp->next;
	if ((*stack)->first != NULL)
		(*stack)->first->prev = NULL;
	tmp->next = NULL;
	tmp->prev = (*stack)->last;
	(*stack)->last->next = tmp;
	(*stack)->last = tmp;
	if (cmd != NULL)
		ft_printf("%s\n", cmd);
	return (0);
}

void	ra(t_stacks **stacks)
{
	int	error;

	error = rotate(&(*stacks)->a, "ra");
	if (error != 0)
		exit(EXIT_FAILURE);
}

void	rb(t_stacks **stacks)
{
	int	error;

	error = rotate(&(*stacks)->b, "rb");
	if (error != 0)
		exit(EXIT_FAILURE);
}

void	rr(t_stacks **stacks)
{
	int	error_a;
	int	error_b;

	error_a = rotate(&(*stacks)->a, NULL);
	error_b = rotate(&(*stacks)->b, NULL);
	ft_printf("rr\n");
	if (error_a != 0 && error_b != 0)
		exit(EXIT_FAILURE);
	else if (error_a != 0 || error_b != 0)
		exit(EXIT_FAILURE);
}
