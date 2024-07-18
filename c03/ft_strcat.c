#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int count;
	char	*newstr;

	i = 0;
	j = 0;
	count = 0;
	while(dest[i] != '\0' || src[i] != '\0')
	{
		if (dest[i] != '\0')
		{
			write(1, &dest[i], 1);
			write(1, " ", 1);
			i++;
		}
		if (src[i] != '\0')
		{
			write(1, &src[i], 1);
			write(1, "\n", 1);
			j++;
		}
	}
	while (count < i)
	{
		newstr[count] = dest[i + count];
		count++;
	}
	while (count < j)
	{
		newstr[count] = src[j + count];
		count++;
	}
	newstr[count + 1] = '\0';
	return (newstr);
}

int	main(int argc, char **argv)
{
	char *newstr;
	int		i;

	i = 0;
	if (argc == 3)
	{
		newstr = ft_strcat(argv[1], argv[2]);
		while (newstr[i] != '\0')
		{
			write(1, newstr, 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
