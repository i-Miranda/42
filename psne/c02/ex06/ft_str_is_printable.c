#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= '!' && str[i] <= '~')
			i++;	
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_printable("TEST") != 0)
		write(1, "printable\n", 10);
	else
		write(1, "not printable\n", 14);
	return (0);
}
