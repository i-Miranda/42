/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:45:34 by ivan              #+#    #+#             */
/*   Updated: 2025/02/21 11:02:45 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_next_value(t_list *list)
{
	t_list *temp;

	temp = list;
	return (*(int *)temp->content < *(int *)temp->next->content);
}

int	check_list_sort(t_stacks **stacks)
{
	t_list *temp;

	temp = (*stacks)->a;
	while (temp->next != NULL)
	{
		if (check_next_value(temp) != ERR_NONE)
			return (ERR_GNRL);
		temp = temp->next;
	}
	free_stacks(*stacks);	
	return (ERR_NONE);
}
