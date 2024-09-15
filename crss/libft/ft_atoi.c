#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		i = i * 10 + str[i] - '0';
		i++;	
	}
	return (i * neg);
}
