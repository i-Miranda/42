#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"

int	ft_printf(char const *, ...);

//Number print functions
int	ft_print_float(float dec);
int	ft_print_int(int nbr);
int	ft_print_ufloat(unsigned float udec);
int	ft_print_lhex(int lhex);
int	ft_print_bhex(int bhex);

//Text print functions
int	ft_print_char(char c)
int	ft_print_string(char *str)
int	ft_print_address(void *addr)
int	ft_print_percent()
