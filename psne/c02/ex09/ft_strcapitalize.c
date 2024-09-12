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

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
 		if (i == 0 || ((str[i - 1] >= '\t' && str[i - 1] <= '\r')
				||(str[i - 1] >= ' ' && str[i - 1] <= '/')
				||(str[i - 1] >= ':' && str[i - 1] <= '@')
				||(str[i - 1] >= '[' && str[i - 1] <= '`')
				||(str[i - 1] >= '{' && str[i - 1] <= '~'))
				&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	main(void)
{
	char str[] = "salut, comment tu vas?42mots quarante-deux; cinquante+et+un";
	ft_putstr(str);
	write(1, "\n", 1);
	ft_strcapitalize(str);
	ft_putstr(str);
	write(1, "\n", 1);
}
