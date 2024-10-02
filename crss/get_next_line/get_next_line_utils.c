#include "get_next_line.h"

t_list	*ft_lst_new(char *content)
{
	t_list *new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	*new->content = content;
	return (new);
}

t_list	*ft_lst_append(t_list **list, t_list *new)
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

char	*build_newline(t_list **list, int nl)
{
	char	*str;
	int		i;
	t_list	*iter;

	str = malloc(nl + 1 * sizeof(list));
	if (!str)
		return (NULL);
	while (i != nl)
	{
		while(iter->next != NULL || iter->content != NULL)
		{		
			if (iter->content != NULL)
				str[i++] = iter->content++;
		}
		iter = iter->next;
	}
	return (str);
}

char	*check_newline(t_list **lst)
{
	t_list	*iter;
	int		i;

	if (!lst)
		return (NULL);
	iter = *lst;	
	i = 0;
	while(iter->next != NULL || iter->content != NULL)
	{
		if (iter->content != NULL)
		{
			while (iter->content[i] != '\n' || iter->content[i] != '\0')
				i++;
		}
		if (iter->next != NULL)
			iter = iter->next;
	}
	if (iter->content[i] == '\n')
		return (build_newline(lst, ++i));
	return (NULL);
}
