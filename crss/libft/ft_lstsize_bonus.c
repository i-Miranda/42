#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (lst->next != NULL)
		return (ft_lstsize(lst->next));
}
