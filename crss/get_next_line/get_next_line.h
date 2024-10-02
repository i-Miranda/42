#include <unistd.h>
#include <stdlib.h>

# define BUFFER_SIZE 10

typedef struct s_list{
	char 			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

// Utils

//list functions
t_list	*ft_lst_new(char *content);
t_list	*ft_lst_last(t_list	*node)
void	ft_lst_append(t_list **list, t_list *new);

int		ft_check_newline(char *c);
