#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;
	int	count;
	char	*newstr;

	i = 0;
	j = 0;
	count = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	count = i + j;
	i = 0;
	j = 0;
	while (count > )
	{
		if (dest[i] != '\0')
		{
			newstr[count] = dest[i];
			i++;
		}
		else if (src[j] != '\0')
		{
			newstr[count] = src[j];
			j++;
		}
		count--;
	}
	newstr[i + j + 1] = '\0';
	write (1, newstr, 1);
	return (newstr);
}

int	main(int argc, char **argv)
{
	char	*newstr;
	int	i;

	i = 0;
	if (argc == 3)
	{
		newstr = ft_strcat(argv[1], argv[2]);
		while (newstr[i] != '\0')
		{
			write(1, &newstr[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
