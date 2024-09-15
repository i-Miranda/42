#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst->next != null)
		ft_lstiter(lst->next);
	f(lst->content);
}
