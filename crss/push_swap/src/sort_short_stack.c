/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/02/11 18:33:20 by ivan              #+#    #+#             */
/*   Updated: 2025/02/11 23:45:27 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	**find_short_stack(t_stacks *stacks)
{
	t_list **shrt;

	if (ft_lstsize(stacks->a) == 3)
		shrt = &(stacks->a);
	else if (ft_lstsize(stacks->b) == 3)
		shrt = &(stacks->b);
	else
		return (NULL);
	return (shrt);
}

static void	set_first_greater(t_list ***shrt)
{
	if (*(int *)shrt->next->content > *(int *)shrt->next->next->content)
	{
		swap(shrt);
		reverse_rotate(shrt);
	}
	else if (*(int *)shrt->content > *(int *)shrt->next->next->content)
		rotate(shrt);
	else
		swap(shrt);
}

static void set_first_less_or(t_list ***shrt)
{
	if (*(int *)shrt->content > *(int *)shrt->next->next->content)
		reverse_rotate(shrt);
	else if (*(int *)shrt->next->content > *(int *)shrt->next->next->content)
	{
		swap(shrt);
		rotate(shrt);
	}
}

void	sort_short_stack(t_stacks **stacks)
{
	t_list **shrt;

	shrt = find_short_stack(*stacks);
	if (shrt == NULL)
		return ;
	if (*(int *)shrt->content > *(int *)shrt->next->content)
		set_first_greater(&shrt);	
	else
		set_first_less_or(&shrt);
}
