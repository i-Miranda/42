#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;	
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	main(int argc, char **argv)
{
	int result;
	char resultchar;

	if (argc == 3)
	{
		result = ft_strcmp(argv[1], argv[2]);
		if (result < 0)
		{
			result *= -1;
			write(1, "-", 1);
		}
		resultchar = result + '0';
		write(1, &resultchar, 1);
		write(1, "\n", 1);
	}
	return (0);
}
