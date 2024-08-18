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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		ft_strlcat(argv[1], argv[2], 3);
		write(1, "\n", 1);
	}
	return (0);
}
