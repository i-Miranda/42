#include <unistd.h>
#include <stdlib.h>

typedef	struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
} t_stock_str;

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
