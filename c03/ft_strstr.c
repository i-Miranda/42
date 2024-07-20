#include <unistd.h>
unsigned int	ft_strlen(char *str)
{
	unsigned int	i;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*writetostr(char *str, int i, char *to_find, int j)
{
	int count;
	char *newstr;

	count = 0;
	while (count < j - 1)
	{
		newstr[count] = to_find[j + count];
		count++;
	}
	while (str[i + count] != '\0')
	{
		newstr[count] = str[i + count];
		count++;
	}
	newstr[count] = '\0';
	return (newstr);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int i;
	unsigned int j;
	unsigned int str_l;
	unsigned int to_find_l;
	char *newstr;
	
	i = 0;
	j = 0;
	str_l = ft_strlen(str);
	to_find_l = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
			while (str[i + j] == to_find[j])
				j++;
			if (to_find[j] == '\0' && j == to_find_l)
			{
				newstr = writetostr(str, i, to_find, j);
				return (newstr);
			}
		}
		j = 0;
		i++;
	}
	return (str);
}

int	main (int argc, char **argv)
{
	if (argc == 3)
	{
		unsigned int result;
		char	*str;

		result = ft_strlen(argv[1]);
		str = ft_strstr(argv[1], argv[2]);
		write(1, str, result); 	
	}
}
