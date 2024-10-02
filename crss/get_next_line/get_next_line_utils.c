#include "get_next_line.h"

t_list	*ft_lst_new(char *content)
{
	t_list *new;
	
	new = malloc(sizeof (t_list));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	*new->content = content;
	return (new);
}

t_list	*ft_lst_last(t_list	*node)
{
	if (!node)
		return (NULL);
	if (node->next != NULL)
	{
		node = node->next;
		ft_lst_last(node);
	}
	return (node);
}

void	ft_lst_append(t_list *list, t_list *new)
{
	t_list *last_node;
	if (!list || !new)
		return (NULL);
	last_node = ft_lst_back(list);
	last_node->next = new;
}

int	check_newline(char *c)
{
	if (*c == '\n')
		return (1);
	return (0);
}
