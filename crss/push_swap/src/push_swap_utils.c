#include "push_swap.h"

int	build_stack(tStack *a, char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (argv[i] //isAlpha)
		{
			//add to stack a	
		}
		else
		{
			//printf Error
			return (1);
		}
		i++;
	}
	return (0);
}
tStack	*int_to_stack(tStack *a, int *n)
{
	tStack *node;

	if (!a || !n)
		//return (1);
	
	node->content = n;
	node->next = &a; //pretty sure this is wrong
	return (node);
}
