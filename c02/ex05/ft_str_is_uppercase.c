#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			i++;	
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_uppercase("TEST") != 0)
		write(1, "uppercase\n", 10);
	else
		write(1, "not uppercase\n", 14);
	return (0);
}
