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
t_list	*push(t_list *to, t_list *from);
t_list	*pa(t_list *a, t_list *b);
t_list	*pb(t_list *b, t_list *a);

//rotate functions
t_list	*rotate(t_list *list);
t_list	*ra(t_list *a);
t_list	*rb(t_list *b);
void	rr(t_list *a, t_list *b);

//reverse_rotate functions
t_list	*reverse_rotate(t_list *list);
t_list	*rra(t_list *a);
t_list	*rrb(t_list *b);
void	rrr(t_list *a, t_list *b);

//push_swap utils
int	build_list(t_list *a, char *arg);
