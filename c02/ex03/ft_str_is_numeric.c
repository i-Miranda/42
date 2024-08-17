#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;	
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_numeric("1234") != 0)
		write(1, "numeric\n", 7);
	else
		write(1, "not numeric\n", 11);
	return (0);
}
