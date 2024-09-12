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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (&(str[i - j]));
		}
		i++;
	}
	return (NULL);	
}

int	main(int argc, char **argv)
{
	char	*newstr;

	ft_putstr(argv[1]);
	write(1, "\n", 1);
	if (argc == 3)
	{
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		newstr = ft_strstr(argv[1], argv[2]);
	}
	else
	{
		write(1, "missing second arg", 18);
		newstr = ft_strstr(argv[1], ""); 
	}
	if (newstr != NULL)
	{
		write(1, "\n", 1);
		ft_putstr(newstr);
	}
	else
		write(1, "to_find not found", 17);
	write(1, "\n", 1);
}
