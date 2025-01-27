/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:24:25 by ivmirand          #+#    #+#             */
/*   Updated: 2025/01/27 09:30:58 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	build_stack(tStack *a, char *arg)
{
	int	i;
	int	atoi;

	i = 0;
	while (arg[i] != '\0')
	{
		if (argv[i] /*!isDigit*/)
		{
			//printf Error
			return (1);
		}
		i++;
	}
	//n = atoi arg
	int_to_stack(a, n);
	return (0);
}
tStack	*int_to_stack(tStack *a, int *n)
{
	tStack *node;

	if (!a || !n)
		//return (1);
	
	node->content = n;
	node->next = &a; //pretty sure this is wrong
	return (node);
}
