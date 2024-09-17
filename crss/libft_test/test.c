#include "../libft/libft.h"

static int lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void catfunc(char *name)
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

static void	funcresult(char *result, char *expected)
{
	int i;
	int j;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] != expected[i])
		{
			write(1, "FAIL\n", 5);
			j = 0;
			while (j < lenstr(result))
			{
				write(1, "\n", 1);
				write(1, &result[j], 1);
				j++;
			}
			j = 0;
			while (j < lenstr(expected))
			{
				write(1, &result[j], 1);
				write(1, "\n", 1);
				j++;
			}
			return;
		}
		i++;
	}
	write(1, "PASS\n", 5);
}

//!---TESTS---!//

void	test_ft_issomething(int(*f)(int), char *expected)
{
	int		i;
	int		fresult;
	char	*results;

	results = malloc(lenstr(expected) * sizeof(char));
	i = 0;
	while (i < 128)
	{
		fresult = f(i);
		if (fresult != 0)
			results[i] = i;	
		i++;
	}
	funcresult(results, expected);
	free(results);
}

void	test_ft_strlen(char *str, size_t expected)
{
	size_t	i;

	i =	ft_strlen(str);
	funcresult(i, expected);
}

void	test_ft_memset(int c, size_t len)
{
	void	*testptr;
	char	*xpctptr;

	xpctptr = (char *)testptr;	
	while (len > 0)
	{
		len--;
		xpctptr[len] = c;
	}
	ft_memset(vptr, c, len);
	funcresult((char *)testptr, (char *)xpctptr);
}

int	main(void)
{
	system("cat libft.h");
	write(1, "\n", 1);
	test_ft_issomething(ft_isalpha, 
			"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	test_ft_issomething(ft_isdigit,
			"0123456789");
	test_ft_issomething(ft_isalnum,
			"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	test_ft_issomething(ft_isascii);
	test_ft_issomething(ft_isprint);
	write(1, "\n", 1);
	test_ft_strlen("0123456789", 10 * sizeof(char));
	write(1, "\n", 1);
	test_memset(testptr, c, len, xpctptr);
	return (0);
}
