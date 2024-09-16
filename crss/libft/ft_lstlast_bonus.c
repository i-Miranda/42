#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list 	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return(temp);
}
