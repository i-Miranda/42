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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < nb)	
	{
		dest[i + j] = src[j];	
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *newstr;

		ft_putstr(argv[1]);	
		write(1, "\n", 1);
		ft_putstr(argv[2]);	
		write(1, "\n", 1);
		newstr = ft_strncat(argv[1], argv[2], 2);
		ft_putstr(newstr);
	}
	return (0);
}
