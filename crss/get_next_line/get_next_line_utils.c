#include "get_next_line.h"

t_list	*ft_lst_new(char *content)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	*new->content = content;
	return (new);
}

t_list	*ft_lst_append(t_list *list, t_list *new)
{
	t_list *last_node;
	if (!list || !new)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	list->next = new;
	return (new);
}

t_list	**ft_build_list(t_list **list)
{
	if (!list)
	{
		list = malloc(sizeof(t_list *));
		if (!list)
			return (NULL);
	}
}

t_list	*check_newline(char *c, t_list **list)
{
	t_list *node;

	node = ft_lst_new(c);
	list = ft_lst_append(list, node);
	i = 0;
	while (c[i] != '\n' || c[i] != '\0')
		i++;
	if (c[i] == '\n')
		return ();
	return (NULL);
}
