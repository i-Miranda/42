#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list 	*newlist;
	int		i;

	i = ft_lstsize(lst);
	newlist = malloc(i * sizeof(t_list));
	if (newlist == NULL)
	{
		free(newlist);
		return (NULL);
	}
	i = 0;
	while(lst[i]->next != null)
	{
		newlist[i]->content = f(lst[i]->content);
		del(lst[i]->content);
		free(lst[i])
		i++;
	}
	return (newlist);
}

