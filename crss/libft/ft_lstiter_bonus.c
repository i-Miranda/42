#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
	f(lst->content);
}
