#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		result;
	int		arg_i;
	size_t	len;
	size_t	i;
	va_list	arglist;

	va_start(arglist, str);
	arg_i = 0;
	while (arglist[arg_i])
	{
		va_arg(arglist[arg_i], char const *);
		arg_i++;
	}
	va_end(arglist);
	return (result); 
}
