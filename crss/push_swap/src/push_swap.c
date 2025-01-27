/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:23:55 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 10:34:56 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a)
{
	void *temp;

	if (ft_lstsize(a) > 1)
	{
		temp = a->next->next;
		a->next->next = a->next;
		a->next = temp;
	}
}
void	sb(t_list *b)
{
	if (ft_lstsize(b) > 1)
	{
		temp = b->next->next;
		b->next->next = b->next;
		b->next = temp;
	}
void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}
void	pa(t_list *a, t_list *b)
{
	//if b is not empty
	if (ft_lstsize(b) > 0)
	//get first element in stack b and puts on top of stack a
	b->next = *a;
}
void	pb(t_list *b, t_list *a)
{
	//if a is not empty
	if (ft_lstsize(a) > 0)
	//get first element in stack a and puts on top of stack b
	a->next = *b;
}
void	ra(t_list *a)
{
	t_list *last;
	//moves all elements in stack a up one position so the first element is now
	//the last.
	last = ft_lstlast(a);
	free(a->next);
	last->next = *a;
}
void	rb(t_list *b)
{
	//moves all elements in stack b up one position so the first element is now
	//the last.
}
void	rr(t_list *a, t_list *b)
{
	ra();
	rb();
}
void	rra(t_list *a)
{
	//moves all elements in stack a down one position so the last element is now
	//the first.
}
void	rrb(t_list *b)
{
	//moves all elements in stack b down one position so the last element is now
	//the first.
}
void	rrr(t_list *a, t_list *b)
{
	rra();
	rrb();
}
