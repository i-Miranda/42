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

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0')	
	{
		dest[i + j] = src[i];	
		i++;
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
		newstr = ft_strcat(argv[1], argv[2]);
		ft_putstr(newstr);
	}
	return (0);
}
