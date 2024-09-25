#include <ctype.h>
#include <string.h>
#include <bsd/string.h>
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

static char *buildstr(int start, int end)
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

static char charplusint(unsigned int index, char c)
{
	char result;

	result = c + index;
	return (result);
}

static void	strplusint(unsigned int index, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++] += index;
}

//!---TESTS---!//

void	test_ft_issomething(int(*ft)(int), int(*f)(int), char *func)
{
	int	i;

	i = 0;
	teststr(func);
	while (i < 128)
	{
		if ((ft(i) != 0 && f(i) == 0) || (ft(i) == 0 && f(i) != 0))
		{
			write(1, "\x1b[31m", 5); 
			write(1, "FAIL\n", 5);
			write(1, "\x1b[37m", 5); 
			return;
		}
		i++;
	}
	write(1, "\x1b[32m", 5); 
	write(1, "PASS\n", 5);
	write(1, "\x1b[37m", 5); 
}

void	test_ft_strlen(size_t expected)
{
	size_t	i;
	char	*numstr = buildstr('0', '9');

	teststr("ft_strlen");
	i =	ft_strlen(numstr);
	if (i == expected)
	{
		write(1, "\x1b[32m", 5); 
		write(1, "PASS\n", 5);
		write(1, "\x1b[37m", 5); 
	}
	else
	{
		write(1, "\x1b[31m", 5); 
		write(1, "FAIL\n", 5);
		write(1, "\x1b[37m", 5); 
	}
	free (numstr);
}

void	test_ft_memset(void *testptr, int c, size_t len)
{
	char 	*xpctptr;
	size_t	i;
	size_t	tptrlen;

	teststr("ft_memset");
	i = 0;
	xpctptr = (char *)testptr;
	tptrlen = lenstr(xpctptr);
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
	ft_memset(testptr, c, len);
	funcresult(testptr, xpctptr);
}

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
		char * func, void *dst, const void *src, size_t n, char *expected)
{
		char *result;

		teststr(func);
		result = (char *)mem(dst, src, n);
		funcresult(result, expected);
}

void	test_ft_strlsomething(size_t (*f)(char *, const char *, size_t),
		char *func, char *str, const char *cstr, 
		size_t sizetest, size_t expected)
{
	size_t		result;

	teststr(func);
	sizetest = sizetest * sizeof(char);
	result = f(str, cstr, sizetest); 
	if (result == expected)
	{
		write(1, "\x1b[32m", 5); 
		write(1, "PASS\n", 5);
		write(1, "\x1b[37m", 5); 
	}
	else
	{
		write(1, "\x1b[31m", 5); 
		write(1, "FAIL\n", 5);
		write(1, "\x1b[37m", 5); 
	}
}

void	test_ft_tosomething(int (*to)(int), char *func, 
		char *test, char *expected)
{
	char	*result;
	int		i;

	teststr(func);
	result = malloc((lenstr(test)) * sizeof(char));
	if (result == NULL)
	{
		free(result);
		return ;
	}
	i = 0;
	while (i < lenstr(test))
	{
		result[i] = to(test[i]);
		i++;
	}
	result[i] = '\0';
	funcresult(result, expected);	
}

void	test_ft_strchr(char *(*f)(const char *, int), char *func,
		char *str, int chr, char *position)
{
	char	*result;

	teststr(func);
	result = f(str, chr);
	funcresult(result, position);
}

void	test_ft_strncmp(const char *s1, const char *s2, size_t n, int expected)
{
	int	result;

	teststr("ft_strncmp");
	result = ft_strncmp(s1, s2, n);
	if (result == expected)
	{
		write(1, "\x1b[32m", 5); 
		write(1, "PASS\n", 5);
		write(1, "\x1b[37m", 5); 
	}
	else
	{
		write(1, "\x1b[31m", 5); 
		write(1, "FAIL\n", 5);
		ft_putnbr_fd(ft_strncmp(s1, s2, n), 1);
		write(1, " : ", 3);
		ft_putnbr_fd(strncmp(s1, s2, n), 1);
		write(1, "\x1b[37m", 5); 
		write(1, "\n", 1);
	}
}

void	test_ft_memchr(const char *str, int c, size_t n, char *expected)
{
	char *result;

	teststr("ft_memchr");
	result = ft_memchr(str, c, n);
	funcresult(result, expected);
}

void	test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	ft_result;
	int result;

	teststr("ft_memcmp");
	ft_result = ft_memcmp(s1, s2, n);
	result = memcmp(s1, s2, n);

	if (ft_result == result)
	{
		write(1, "\x1b[32m", 5); 
		write(1, "PASS\n", 5);
		write(1, "\x1b[37m", 5); 
	}
	else
	{
		write(1, "\x1b[31m", 5); 
		write(1, "FAIL\n", 5);
		write(1, "\x1b[37m", 5); 
	}
}

void	test_ft_strnstr(const char *haystack, const char *needle, size_t len, 
		char *expected)
{
	char	*result;

	teststr("ft_strnstr");
	result = ft_strnstr(haystack, needle, len);
	funcresult(result, expected);
}

void	test_ft_atoi(char *ascii, int expected)
{
	int result;
	teststr("ft_atoi");
	result = ft_atoi(ascii);	
	if (result == expected)
	{
		write(1, "\x1b[32m", 5); 
		write(1, "PASS\n", 5);
		write(1, "\x1b[37m", 5); 
	}
	else
	{
		write(1, "\x1b[31m", 5); 
		write(1, "FAIL\n", 5);
		ft_putnbr_fd(ft_atoi(ascii), 1);
		write(1, " : ", 3);
		ft_putnbr_fd(atoi(ascii), 1);
		write(1, "\n", 1);
		write(1, "\x1b[37m", 5); 
	}
}

void	test_ft_calloc(size_t count, size_t size, char *expected)
{
	char	*testptr;
	
	teststr("ft_calloc");
	testptr = ft_calloc(count, size);	
	funcresult(testptr, expected);
}

void	test_ft_strdup(const char *str, char *expected)
{
	char	*result;

	teststr("ft_strdup");
	result = ft_strdup(str);
	funcresult(result, expected);
}

void	test_ft_substr(char	const *s, unsigned int start, size_t len,
		char	*expected)
{
	char	*result;
	
	teststr("ft_substr");
	result = ft_substr(s, start, len);
	funcresult(result, expected);
}

void	test_ft_strsomething(char *(*f)(char const *, char const *), 
		char *func, char const *s1, char const *s2, char *expected)
{
	char	*result;

	teststr(func);
	result = f(s1, s2);
	funcresult(result, expected);
}

void	test_ft_split(char const *s, char c, char **expected)
{
	char 	**result;
	size_t	result_len;
	size_t	expected_len;
	size_t	i;

	teststr("ft_split");
	i = 0;
	expected_len = 0;
	while (expected[i++])
		expected_len++;
	i = 0;
	result_len = 0;
	result = ft_split(s, c);
	while (result[i++])
		result_len++;
	i = 0;
	write(1, "\n", 1);
	while (result[i])
	{
		write(1, "\t", 1);
		teststr(result[i]);
		funcresult(result[i], expected[i]);
		i++;
	}
}

void	test_ft_itoa(int n, char *expected)
{
	char	*result;

	teststr("ft_itoa");
	result = ft_itoa(n);
	funcresult(result, expected);
}

void	test_ft_strmapi(char const *s, char (*f)(unsigned int, char),
		char *expected)
{
	char	*result;
	
	teststr("ft_strmapi");
	result = ft_strmapi(s, f);
	funcresult(result, expected);	
}

void	test_ft_striteri(char const *s, char (*f)(unsigned int, char *),
		char *expected)
{
	teststr("ft_striteri");
	ft_striteri(s, f);
	funcresult(s, expected);	
}

void	test_ft_putsomething_fd(void (*put)(void *, int), char *func,
		void *something, int fd)
{
	teststr(func);	
	put(something, fd);
}

//------TEST COMPILATION--------//
void	test_part_one(void)
{
	char		*numstr;
	char		*alphastr;
	char		*capstr;
	void		*voidnum;
	const void	*cnstvdnum;

	write(1, "\nTESTING PART 1\n", 16);
	test_ft_issomething(ft_isalpha, isalpha, "ft_isalpha");
	test_ft_issomething(ft_isdigit, isdigit, "ft_isdigit");
	test_ft_issomething(ft_isalnum, isalnum, "ft_isalnum");
	test_ft_issomething(ft_isascii, isascii, "ft_isascii");
	test_ft_issomething(ft_isprint, isprint, "ft_isprint");
	write(1, "\n", 1); 

	test_ft_strlen(10);
	write(1, "\n", 1);

	numstr = buildstr('0', '9');
	voidnum = (void *)numstr;
	test_ft_memset(voidnum, 'B', 4);
	test_ft_bzero(voidnum, 4);
	free(numstr);
	write(1, "\n", 1);

	numstr = buildstr('0', '9');
	cnstvdnum = (const void *)numstr;
	alphastr = buildstr('A', 'J');
	test_ft_memcpymove(ft_memcpy, "ft_memcpy", alphastr, &cnstvdnum[8],
			5, "89"); 
	test_ft_memcpymove(ft_memmove, "ft_memmove", (void *)cnstvdnum, &cnstvdnum[3], 
			5, (char *)cnstvdnum); 
	free(numstr);
	free(alphastr);
	write(1, "\n", 1);

	numstr = buildstr('0', '9');
	alphastr = buildstr('A', 'J');
	test_ft_strlsomething(ft_strlcpy, "ft_strlcpy", numstr,
			(const char *)alphastr, 4, 4);
	free(numstr);
	free(alphastr);

	numstr = buildstr('0', '9');
	alphastr = buildstr('A', 'J');
	test_ft_strlsomething(ft_strlcat, "ft_strlcat", numstr, 
			(const char *)alphastr, 14, 20);
	free(numstr);
	free(alphastr);
	write(1, "\n", 1);

	alphastr = buildstr('a', 'z');
	capstr = buildstr('A', 'Z');
	test_ft_tosomething(ft_toupper, "ft_toupper", alphastr, capstr);
	free(alphastr);
	free(capstr);

	alphastr = buildstr('a', 'z');
	capstr = buildstr('A', 'Z');
	test_ft_tosomething(ft_tolower, "ft_tolower", capstr, alphastr);
	free(alphastr);
	free(capstr);
	write(1, "\n", 1);

	alphastr = buildstr('A', 'I');
	test_ft_strchr(ft_strchr, "ft_strchr", alphastr, 'A', &alphastr[0]);
	test_ft_strchr(ft_strrchr, "ft_strrchr", alphastr, 'H', &alphastr[7]);
	free(alphastr);
	write(1, "\n", 1);

	// FAILS
	test_ft_strncmp("AB", "ABC", 3, strncmp("AB", "ABC", 3));
	write(1, "\n", 1);

	capstr = buildstr('A', 'Z');
	test_ft_memchr(capstr, 'D', 6, 
			&capstr[3]);
	free(capstr);
	write(1, "\n", 1);

	test_ft_memcmp("test 1", "test 2", 4);
	write(1, "\n", 1);

	capstr = buildstr('A', 'J');
	alphastr = buildstr('C', 'F');
	test_ft_strnstr(capstr, alphastr, 8, strnstr(capstr, alphastr, 8));
	free(capstr);
	free(alphastr);
	write(1, "\n", 1);

	test_ft_atoi("  -1b23456789", atoi("  -1b23456789"));
	test_ft_calloc(8, 1, "00000000");	
	test_ft_strdup("0123456789", "0123456789");
}

void	test_part_two(void)
{
	char	*alphastr;
	char	*numstr;

	write(1, "\nTESTING PART 2\n", 16);
	alphastr = buildstr('A', 'Z');
	test_ft_substr(alphastr, 0, 4, "ABCD");
	free(alphastr);
	write(1, "\n", 1);
	alphastr = buildstr('A', 'D');
	numstr = buildstr('0', '9');
	test_ft_strsomething(ft_strjoin, "ft_strjoin", alphastr, numstr,
			"ABCD0123456789");
	free(alphastr);
	free(numstr);
	alphastr = buildstr('0', '9');
	test_ft_strsomething(ft_strtrim, "ft_strtrim", alphastr, "01289",
			"34567");
	test_ft_strsomething(ft_strtrim, "ft_strtrim", alphastr, "9876",
			"012345");
	test_ft_strsomething(ft_strtrim, "ft_strtrim", "012310", "01",
			"23");
	free(alphastr);
	write(1, "\n", 1);
	char **splittest;
	
	splittest = malloc(2 * sizeof(char *));
	splittest[0] = malloc(4 * sizeof(char));
	splittest[0] = "AAAA";
	splittest[1] = malloc(4 * sizeof(char));
	splittest[1] = "BBBB";
	test_ft_split("AAAAbCCCC", 'b', splittest);	
	free(splittest);
	// SEGFAULT	
	//test_ft_itoa(123456789, "123456789");
	//ft_putstr_fd(ft_itoa(1), 1);
	test_ft_strmapi("AAAA", charplusint, "ABCD");
	write(1, "\n", 1);
	// SEGFAULT
	//test_ft_striteri("AAAA", strplusint, "ABCD");
	write(1, "\n", 1);
	test_ft_putsomething_fd(ft_putchar_fd, "ft_putchar_fd", 'c', 1);
	write(1, "\n", 1);
	test_ft_putsomething_fd(ft_putstr_fd, "ft_putstr_fd", "str test", 1);
	write(1, "\n", 1);
	test_ft_putsomething_fd(ft_putendl_fd, "ft_putendl_fd", "endl test", 1);
	write(1, "\n", 1);
	test_ft_putsomething_fd(ft_putnbr_fd, "ft_putnbr_fd", 1234, 1);
}

void	test_bonus(void)
{
	write(1, "\nTESTING BONUS\n", 15);
}

int	main(int argc, char *argv[])
{
	if (argc == 1 || argc == 2 || argc == 3)
	{
		if (argc == 3 && ft_strncmp(argv[2], "norminette", 5))
			system("cd ../libft; norminette");
		if (argc == 1 || ft_strncmp(argv[1], "1", 5))
			test_part_one();
		if (argc == 1 || ft_strncmp(argv[1], "2", 5)) 
			test_part_two();
		if (argc == 1 || ft_strncmp(argv[1], "bonus", 5))
			test_bonus();
	}
	return (0);
}
