#include "libft.h"

static int lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	teststr(char *func)
{
	write(1, "Testing ", 8);
	write(1, func, lenstr(func));
	write(1, " ", 1);
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
			write(1, "\x1b[31m", 5); 
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

static char *buildstr(int start, int end)
{
	char	*str;
	int		i;

	str = malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < end - start + 1)
	{
		str[i] = start + i;	
		i++;
	}
	return (str);
}

//!---TESTS---!//

void	test_ft_issomething(int(*f)(int), char *func, char *expected)
{
	int		i;
	int		fresult;
	char	*results;

	teststr(func);
	results = malloc(lenstr(expected) * sizeof(char));
	if (results == NULL)
	{
		free(results);
		return;
	}
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

	teststr("ft_strlen");
	i =	ft_strlen(str);
	if (i == expected)
		write(1, "PASS\n", 5);
	else
		write(1, "FAIL\n", 5);
}

void	test_ft_memsomething(void *(f)(void *, int, size_t),
		char *func, void *testptr, int c, size_t len)
{
	char 	*xpctptr;
	size_t	i;
	size_t	tptrlen;

	teststr(func);
	tptrlen = lenstr(testptr);
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

	teststr("ft_bzero");
	tptrlen = lenstr(testptr);
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

void	test_ft_memcpymove(void *(*mem)(void *, const void *, size_t),
		void *dst, const void *src, size_t n, char *expected)
{
		char *result;

		result = (char *)mem(dst, src, n);
		funcresult(result, expected);
}

void	test_ft_strlsomething(size_t (*f)(char *, const char *, size_t),
		char *func, size_t sizetest, size_t expected)
{
	size_t		result;
	char		chrptr[] = {0,1,2,3,4,5,6,7,8,9}; 
	const char	*cnstptr = "ABCDEFGHIJ"; 

	teststr(func);
	cnstptr = "ABCDEFGHIJ"; 
	sizetest = 4 * sizeof(char);
	result = f(chrptr, cnstptr, sizetest); 
	if (result == expected)
		write(1, "PASS\n", 5);
	else
		write(1, "FAIL\n", 5);
}

void	test_ft_calloc(size_t count, size_t size, char *expected)
{
	char *testptr;
	
	teststr("calloc");
	testptr = calloc(count, size);	
	funcresult(testptr, expected);
}

void	test_ft_strdup(const char *str, char *expected)
{
	char *result;

	teststr("ft_strdup");
	result = ft_strdup(str);
	funcresult(result, expected);
}

int	main(void)
{
	char *numstr;
	char *asciitest;
	void *src = malloc(ft_strlen("Test 1 Source"));
	char dst[6] = "Test 1";

	system("cd ../libft; norminette");
	system("cat libft.h");
	test_ft_issomething(ft_isalpha, "ft_isalpha", 
			"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	test_ft_issomething(ft_isdigit, "ft_isdigit",
			numstr);
	test_ft_issomething(ft_isalnum, "ft_isalnum",
			"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	asciitest = buildstr(0, 127);
	test_ft_issomething(ft_isascii, "ft_isascii", asciitest);
	free(asciitest);
	asciitest = buildstr(30, 127);
	test_ft_issomething(ft_isprint, "ft_isprint", asciitest);
	free(asciitest);
	write(1, "\n", 1); numstr = buildstr('0', '9');
	test_ft_strlen(numstr, lenstr(numstr));
	free(numstr);
	write(1, "\n", 1);
	//numstr = buildstr('0', '9');
	//test_ft_memsomething(ft_memset, "ft_memset", &numstr, 'B', 4);
	//free(numstr);
	//numstr = buildstr('0', '9');
	//test_ft_bzero(&numstr, 4);
	//free(numstr);
	//numstr = buildstr('0', '9');
	//test_ft_memsomething(ft_memchr, "ft_memchr", &numstr, 'B', 4);
	//free(numstr);
	write(1, "\n", 1);
	test_ft_strlsomething(ft_strlcpy, "ft_strlcpy", 4, 4);
	test_ft_strlsomething(ft_strlcat, "ft_strlcat", 10, 20);
	write(1, "\n", 1);
	test_ft_memcpymove(ft_memcpy, dst, &((const void *)src)[8], 5, "Source Source"); 
	test_ft_calloc(8, 1, "00000000");	
	//numstr = buildstr('0', '9');
	//test_ft_strdup((const char *)numstr, "0123456789");
	//free(numstr);
	free(src);	
	return (0);
}
