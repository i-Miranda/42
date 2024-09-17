#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list 	*temp;
	int 	i;
	
	temp = lst;
	if (temp == NULL)
		i = 0;
	else
	{
		i = 1;
		while (temp->next != NULL)
		{
			temp = temp->next;
			i++;
		}
	}
	return (i);
}
