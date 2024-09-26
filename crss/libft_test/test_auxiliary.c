#include "test.h"

int	lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	teststr(char *func)
{
	write(1, "Testing ", 8);
	write(1, func, lenstr(func));
	write(1, " ", 1);
}

void	catfunc(char *name)
{
	int i;
	int len;
	char catcmd[] = {'c', 'a', 't', ' ', '-', 'e', ' ', '\0'};
	char *catstr;

	i = 0;
	len = lenstr(name);
	write(1, "\nTesting ", 10);
	while (i < len)
		write(1, &name[i++], 1);
	write(1, " :\n", 3);
	i = 0;
	catstr = malloc((len + 7) * sizeof(char));
	while (i < (len + 7))
	{
		if (i < 7)
			catstr[i] = catcmd[i];	
		else
			catstr[i] = name[i - 7];
		i++;
	}
	system(catstr);
	free(catstr);
}

void	funcresult(char *result, char *expected)
{
	int i;
	int j;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] != expected[i])
		{
			write(1, "\x1b[31m", 5); 
			write(1, "FAIL\n", 5);
			write(1, "\x1b[37m", 5); 
			j = 0;
			while (j < lenstr(result))
			{
				write(1, &result[j], 1);
				j++;
			}
			write(1, " : ", 3);
			j = 0;
			while (j < lenstr(expected))
			{
				write(1, &expected[j], 1);
				j++;
			}
			write(1, "\n", 1);
			return;
		}
		i++;
	}
	write(1, "\x1b[32m", 5); 
	write(1, "PASS\n", 5);
	write(1, "\x1b[37m", 5); 
}

char	*buildstr(int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((end - start) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	while (i <= (end - start))
	{
		str[i] = start + i;	
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	charplusint(unsigned int index, char c)
{
	char result;

	result = c + index;
	return (result);
}

void	strplusint(unsigned int index, char *str)
{
	*str += index;
}
