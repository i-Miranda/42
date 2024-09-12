#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}	

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int	main (int argc, char **argv)
{
	if (argc == 2)
	{
		write(1, "string is : ", 12);
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		ft_strlowcase(argv[1]);
		write(1, "strlowcase is : ", 16);
		ft_putstr(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "Please input one string.\n", 25);
	return (0);
}
