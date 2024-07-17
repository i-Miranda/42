#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i + 1] = '\0';
	return (dest);	
}

int	main(int argc, char **argv)
{
	char new[5];
	char *input;

	if (argc == 2)
	{

		input = argv[1];
		ft_strcpy(new, input);
		write(1, input, 5);
		write(1, "\n", 1);
		write(1, new, 5);
	}
}
