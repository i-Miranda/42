/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:41:41 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/09 13:40:32 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "libft.h"
# include "printf.h"

# define ERR_NONE 0
# define ERR_GNRL 1

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		a_size;
	int		b_size;
	int		min_val;
	int		mid_val;
	int		max_val;
}t_stacks;

//push_swap
void	push_swap(t_stacks **stacks);

//swap functions
void	swap(t_list **list);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//push functions
void	push(t_list **to, t_list **from);
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);

//rotate functions
void	rotate(t_list **list);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//reverse_rotate functions
void	reverse_rotate(t_list **list);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//push_swap_utils functions
int		init_stacks(t_stacks **stacks);
void	free_split(char **split);
void	free_stacks(t_stacks *stacks);
int		find_duplicate_values(t_stacks *stacks);

//parse functions
int		parse_arg(t_stacks **stacks, char *arg);

//sort functions
int		check_list_sort(t_stacks **stacks);
#endif
