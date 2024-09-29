/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 01:53:11 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/29 04:17:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	print_content(void *content)
{

	printf("%s ", (char *)content);
}

static void	*getnew_content(void *content)
{
	char *newcontent;

	printf("%s ", (char *)content);
	newcontent = (char *)content;
	return (&newcontent[1]);
}

static void	del_content(void *content)
{
	content = NULL;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		//Bonus test
		t_list *head;
		t_list *node1;
		t_list *node2;
		t_list *node3;
		t_list *node4;
		
		head = ft_lstnew("00");
		node1 = ft_lstnew("AA");
		ft_lstadd_back(&head, node1);
		node2 = ft_lstnew("BB");
		ft_lstadd_back(&head, node2);
		node3 = ft_lstnew("CC");
		ft_lstadd_back(&head, node3);
		node4 = ft_lstnew("DD");
		ft_lstadd_front(&head, node4);
		ft_putnbr_fd(ft_lstsize(head), 1);
		ft_putendl_fd(" nodes in list", 1);
			
		ft_putstr_fd("head: ", 1);
		printf("%p\n", head);
		ft_putstr_fd("node 1: ", 1);
		printf("%p\n", node1);
		ft_putstr_fd("node 2: ", 1);
		printf("%p\n", node2);
		ft_putstr_fd("node 3: ", 1);
		printf("%p\n", node3);
		ft_putstr_fd("node 4 added to front: ", 1);
		printf("%p\n", node4);
		ft_lstiter(head, print_content);
		printf("\n");
		ft_putstr_fd("node 4 at front: ", 1);	
		printf("%p\n", node4);
		ft_putstr_fd("head: ", 1);
		printf("%p\n", head);
		ft_putstr_fd("node 1: ", 1);	
		printf("%p\n", node1);
		ft_putstr_fd("node 2: ", 1);	
		printf("%p\n", node2);
		ft_putstr_fd("node 3: ", 1);	
		printf("%p\n", node3);
		ft_putstr_fd("\nnode 3 is the last: ", 1);	
		printf("%p\n", ft_lstlast(head));

		ft_putstr_fd("node 4 at: ", 1);	
		printf("%p\n", node4);
		ft_putstr_fd(" content is: ", 1);	
		print_content(node4->content);
		t_list *newlist;
		newlist = ft_lstmap(head, getnew_content, del_content);
		ft_putendl_fd("", 1);
		ft_lstiter(newlist, print_content);
		ft_lstclear(&newlist, del_content);
	}
	if (argc == 2)
	{
		//ISsomething test
		int	i;

		i = 0;
		ft_putstr_fd("FT_STRLEN of ", 1);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" is: ", 1);
		ft_putendl_fd(ft_itoa(ft_strlen(argv[2])), 1);
		ft_putstr_fd("FT_ATOI of ", 1);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" is: ", 1);
		ft_putnbr_fd(ft_atoi(argv[2]), 1);
		ft_putendl_fd("", 1);
		while (i < ft_strlen(argv[2]))
		{
			if (ft_toupper(argv[2][i]) != argv[2][i])
				ft_putchar_fd(ft_toupper(argv[2][i]), 1);
			if (ft_tolower(argv[2][i]) != argv[2][i])
				ft_putchar_fd(ft_tolower(argv[2][i]), 1);
			if (ft_isdigit(argv[2][i]) != argv[2][i])
				ft_putchar_fd(argv[2][i], 1);
			ft_putstr_fd(" : ", 1);
			if (ft_isalpha(argv[2][i]) == 1)
				ft_putstr_fd("isalpha ", 1);
			if (ft_isdigit(argv[2][i]) == 1)
				ft_putstr_fd("isdigit ", 1);
			if (ft_isalnum(argv[2][i]) == 1)
				ft_putstr_fd("isalnum ", 1);
			if (ft_isascii(argv[2][i]) == 1)
				ft_putstr_fd("isascii ", 1);
			if (ft_isprint(argv[2][i]) == 1)
				ft_putstr_fd("isprint ", 1);
			ft_putendl_fd("", 1);
			i++;
		}
	}
	//TWO strings test
	else if (argc == 3) 
	{
		ft_putstr_fd("FT_STRNCMP (n 6): ", 1);
		if (ft_strncmp(argv[1], argv[2], 6) == 0)
			ft_putendl_fd("EQUAL", 1);
		else
			ft_putendl_fd("NOT EQUAL", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" = ", 1);
		ft_putendl_fd(ft_itoa(ft_atoi(argv[1]) + ft_atoi(argv[2])), 1);
		
		char	*arg1;
		char	*arg2;
		char	*catargs;
		char	**splitarr;
		int		i;

		arg1 = ft_strdup(argv[1]);
		if (!arg1)
			return (1);
		ft_memset(arg1, 'A', ft_strlen(arg1));
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" after memset 'A': ", 1);
		ft_putendl_fd(arg1, 1);

		arg2 = ft_strdup(argv[2]);
		if (!arg2)
			return (2);
		ft_memset(arg2, 'B', ft_strlen(arg2));
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" after memset 'B': ", 1);
		ft_putendl_fd(arg2, 1);

		catargs = ft_calloc(ft_strlen(arg1) + ft_strlen(arg2), 
				sizeof(char));			
		if (!catargs)
			return (1);
		ft_putstr_fd("FT_STRLCAT (dstsize 6) of ", 1);
		ft_putstr_fd(arg1, 1);
		ft_putstr_fd(" + ", 1);
		ft_putstr_fd(arg2, 1);
		ft_putstr_fd(" : ", 1);
		ft_putnbr_fd(ft_strlcat(arg1, arg2, 7), 1); 
		ft_putendl_fd("", 1);
		ft_putstr_fd("New string is: ", 1);
		ft_putendl_fd(arg1, 1);

		ft_putstr_fd("FT_STRLCPY (dstsize 5) of ", 1);
		ft_putstr_fd(arg1, 1);
		ft_putnbr_fd(ft_strlcpy(catargs, arg1, 5), 1); 
		ft_putendl_fd("", 1);
		ft_putstr_fd("New string is: ", 1);
		ft_putendl_fd(catargs, 1);

		catargs = ft_calloc(ft_strlen(argv[1]) + ft_strlen(argv[2]), 
				sizeof(char));			
		if (!catargs)
			return (1);
		ft_putstr_fd("FT_STRJOIN of ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" = ", 1);
		catargs = ft_strjoin(argv[1], argv[2]);
		ft_putendl_fd(catargs, 1);

		catargs = ft_calloc(ft_strlen(argv[1]) + ft_strlen(argv[2]), 
				sizeof(char));			
		if (!catargs)
			return (1);
		ft_putstr_fd("FT_STRTRIM of ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" = ", 1);
		catargs = ft_strtrim(argv[1], argv[2]);
		ft_putendl_fd(catargs, 1);
			
		catargs = ft_calloc(ft_strlen(argv[1]) + ft_strlen(argv[2]), 
				sizeof(char));			
		if (!catargs)
			return (1);
		ft_putstr_fd("FT_STRNSTR of ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putstr_fd(argv[2], 1);
		ft_putstr_fd(" = ", 1);
		catargs = ft_strnstr(argv[1], argv[2], ft_strlen(argv[1]));
		ft_putendl_fd(catargs, 1);

		catargs = ft_calloc(ft_strlen(argv[1]) + ft_strlen(argv[2]), 
				sizeof(char));			
		if (!catargs)
			return (1);
		ft_putstr_fd("FT_STRCHR of ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putchar_fd(argv[2][0], 1);
		ft_putstr_fd(" = ", 1);
		catargs = ft_strchr(argv[1], argv[2][0]);
		ft_putendl_fd(catargs, 1);

		catargs = ft_calloc(ft_strlen(argv[1]) + ft_strlen(argv[2]), 
				sizeof(char));			
		if (!catargs)
			return (1);
		ft_putstr_fd("FT_STRRCHR of ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putchar_fd(argv[2][0], 1);
		ft_putstr_fd(" = ", 1);
		catargs = ft_strrchr(argv[1], argv[2][0]);
		ft_putendl_fd(catargs, 1);

		ft_putstr_fd("FT_SPLIT of ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd(" + ", 1);
		ft_putchar_fd(argv[2][0], 1);
		ft_putendl_fd(" : ", 1);
		splitarr = ft_split(argv[1], argv[2][0]);
		i = 0;
		while (splitarr[i])
		{
			ft_putendl_fd(splitarr[i], 1);
			free(splitarr[i]);
			i++;
		}
		free(splitarr);

		catargs = ft_calloc(ft_strlen(argv[1]) + ft_strlen(argv[2]), 
				sizeof(char));			
		if (!catargs)
			return (1);
		free(catargs);
		free(arg1);
		free(arg2);
	}
	//*ft_memcpy(void *dst, const void *src, size_t n);
	//*ft_memmove(void *dst, const void *src, size_t len);
	//*ft_memchr(const void *s, int c, size_t n);
	//ft_memcmp(const void *s1, const void *s2, size_t n);

	//*ft_substr(char const *s, unsigned int start, size_t len);
	//*ft_strmapi(char const *s, char (*f)(unsigned int, char));
	//ft_striteri(char *s, void (*f)(unsigned int, char*));
}
