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
	if (i == expected)
		write(1, "PASS", 4);
	else
		write(1, "FAIL", 4);
}

void	test_ft_memsomething(void *(f)(void *, int, size_t),
		void *testptr, int c, size_t len)
{
	char 	*xpctptr;
	size_t	i;
	size_t	tptrlen;

	tptrlen = ft_strlen(testptr);
	i = 0;
	xpctptr = (char *)testptr;
	while (i < tptrlen)
	{
		xpctptr[i] = ((char *)testptr)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		xpctptr[i] = c;
		i++;
	}
	f(testptr, c, len);
	funcresult(testptr, xpctptr);
}

// this test is kinda bullshit
void	test_ft_bzero(void *testptr, size_t len)
{
	char 	*xpctptr;
	size_t	i;
	size_t	tptrlen;

	tptrlen = ft_strlen(testptr);
	i = 0;
	xpctptr = (char *)testptr;
	while (i < tptrlen)
	{
		xpctptr[i] = ((char *)testptr)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		xpctptr[i] = 0;
		i++;
	}
	ft_bzero(testptr, len);
	funcresult(testptr, xpctptr);
}

int	main(void)
{
	char numstr[10] = "0123456789";

	system("cat libft.h");
	test_ft_issomething(ft_isalpha, 
			"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	test_ft_issomething(ft_isdigit,
			"0123456789");
	test_ft_issomething(ft_isalnum,
			"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	//test_ft_issomething(ft_isascii);
	//test_ft_issomething(ft_isprint);
	write(1, "\n", 1);
	test_ft_strlen(numstr, ft_strlen(numstr));
	write(1, "\n", 1);
	test_ft_memsomething(ft_memset, &numstr, 'B', 4);
	test_ft_bzero(&numstr,4);
	//test_ft_memsomething(ft_memchr, &numstr, 'B', 4);
	write(1, "\n", 1);
	return (0);
}
