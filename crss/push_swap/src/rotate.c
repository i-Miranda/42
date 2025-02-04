/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:54:09 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/04 10:30:34 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//moves all elements in stack a up one position so the first element is now
//the last.
void	rotate(t_list **list)
{
	t_list	*temp;

	temp = *list;
	ft_lstadd_back(&temp, temp->next);
	temp = temp->next->next;
	free(ft_lstlast(temp)->next);
	*list = temp;
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
