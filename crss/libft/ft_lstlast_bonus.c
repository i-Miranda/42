#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst->next != null)
		ft_lstlast(lst->next);
	else
		return (lst);
}
