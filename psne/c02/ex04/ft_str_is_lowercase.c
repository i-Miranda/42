#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			i++;	
		else
			return (0);
	}
	return (1);
}

int	main(void)
{
	if (ft_str_is_lowercase("test") != 0)
		write(1, "lowercase\n", 10);
	else
		write(1, "not lowercase\n", 14);
	return (0);
}
