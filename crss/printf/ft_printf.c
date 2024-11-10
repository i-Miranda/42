#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		arg_i;
	int		pct_i;
	size_t	len;
	size_t	i;
	va_list	arglist;

	va_start(arglist, str);
	arg_i = 0;
	while (arglist)
	{
		va_arg(arglist, char const *);
		arg_i++;
	}
	va_end(arglist);
	return (ft_strlen(str));
}
