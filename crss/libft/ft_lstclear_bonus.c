#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (*lst->next != '\0')
	{
		ft_lstclear(*lst->next);
		ft_lstdelone(*lst->next);	
	}
	lst = NULL;
}
