/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:41:41 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/21 11:52:01 by ivmirand         ###   ########.fr       */
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

typedef struct s_node
{
	struct s_stack	*head;
	struct s_node	*prev;	
	struct s_node	*next;	
	unsigned int	index;
	int				value;
}t_node;

typedef struct s_stack
{
	struct s_stacks	*parent;
	t_node			*first;	
	t_node			*last;	
	int				size;
}t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		*a_size;
	int		*b_size;
	int		min_val;
	int		mid_val;
	int		max_val;
}t_stacks;

//push_swap
void	push_swap(t_stacks **stacks);

//swap functions
void	swap(t_stack **stack);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//push functions
void	push(t_stack **to, t_stack **from);
void	pa(t_stacks **stacks);
void	pb(t_stacks **stacks);

//rotate functions
void	rotate(t_stack **stack);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//reverse_rotate functions
void	reverse_rotate(t_list **list);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//stack functions
void	free_stack(t_stack *stack);
void	free_stacks(t_stacks *stacks);
int		init_stack(t_stack *stack, t_stacks *parent);
int		init_stacks(t_stacks **stacks);

//node functions
t_node	*init_node(int value, t_stack *parent);
void	node_to_bottom(t_node *node, t_stack *stack);
void	node_to_top(t_node *node, t_stack *stack);

//parse functions
int		find_duplicate_values(t_stacks *stacks);
int		parse_arg(t_stacks **stacks, char *arg);

//sort functions
#endif
