/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:41:41 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 07:36:06 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node			*first;
	t_node			*last;
	int				size;
	int				max_val;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

//swap functions
void	sa(t_stacks **stacks);
void	sb(t_stacks **stacks);
void	ss(t_stacks **stacks);

//push functions
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);

//rotate functions
void	ra(t_stacks **stacks);
void	rb(t_stacks **stacks);
void	rr(t_stacks **stacks);

//reverse_rotate functions
void	rra(t_stacks **stacks);
void	rrb(t_stacks **stacks);
void	rrr(t_stacks **stacks);

//stack functions
t_node	*init_node(int value, t_stack **stack);
int		free_stacks(t_stacks **stacks, int error);
int		init_stacks(t_stacks **stacks);

//parse functions
int		find_duplicate_values(t_stacks *stacks);
int		parse_arg(t_stacks **stacks, char *arg);

//index functions
void	sort_values(int *values, int size);
int		get_indices(t_stack **stack);

//sort functions
void	ps_sort_2(t_stacks **stacks);
void	ps_sort_3(t_stacks **stacks);
void	ps_sort_4(t_stacks **stacks);
void	ps_sort_5(t_stacks **stacks);

//k_sort functions
void	k_sort_start(t_stacks **stacks);
void	k_sort_end(t_stacks **stacks);
#endif
