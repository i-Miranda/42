#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;

	newlist = malloc(sizeof(t_list));
	if (newlist == NULL)
	{
		free(newlist);
		return (NULL);
	}
	f(lst->content);
	del(lst->content);
}
