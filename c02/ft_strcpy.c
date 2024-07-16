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
	dest[i] = '\0';
	return (dest);	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *new;
		char *input;

		input = argv[1];
		new = ft_strcpy(new, input);
		write(1, input, 5);
		write(1, "\n\0", 2);
		write(1, new, 5);
		write(1, "\n\0", 2);
	}
}
