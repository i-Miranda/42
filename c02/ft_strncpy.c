#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int len)
{
	int	i;

	i = 0;
	while(i > len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);	
}

int	main(int argc, char **argv)
{
	char *new;
	char *input;

	if (argc == 2)
	{

		input = argv[1];
		ft_strncpy(new, input, 5);
		write(1, input, 5);
		write(1, "\n", 1);
		write(1, new, 5);
		write(1, "\n", 1);
	}
}
