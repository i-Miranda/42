#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

typedef struct s_stacks{
	t_list	*a;
	t_list	*b;
}t_stacks

//push_swap
void	push_swap(t_list *a, t_list *b)

//swap functions
void	swap(t_list *list);
void	sa(t_list *a);
void	sb(t_list *b);
void	ss(t_list *a, t_list *b);

//push functions
void	push(t_list *to, t_list *from);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

//rotate functions
void	rotate(t_list *list);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//reverse_rotate functions
void	reverse_rotate(t_list *list);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

//push_swap utils
int	build_list(t_list *a, char *arg);
