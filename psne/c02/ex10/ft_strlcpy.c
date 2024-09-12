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

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

int	main (int argc, char **argv)
{
	char *dest;
	char *src;

	if (argc == 3)
	{
		dest = argv[1];	
		src = argv[2];	
		write(1, "dest is: ", 9);
		ft_putstr(dest);
		write(1, "\nsrc is: ", 9);
		ft_putstr(src);
		write(1, "\n", 1);
		ft_strlcpy(dest, src, ft_strlen(dest) + 1);
		write(1, "dest is: ", 9);
		ft_putstr(dest);
		write(1, "\nsrc is: ", 9);
		ft_putstr(src);
		write(1, "\n", 1);
	}
	return (0);	
}
