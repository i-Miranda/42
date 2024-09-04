#include <unistd.h>

#define EVEN(n) (n % 2)
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
#define SUCCESS 0
#define TRUE 0
#define FALSE 1

typedef unsigned char t_bool;

void	ft_putstr(char *str);

t_bool	ft_is_even(int nbr);
