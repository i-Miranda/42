#include "test.h"

//!---TESTS---!//

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

void	test_ft_striteri(char *s, void (*f)(unsigned int, char *),
		char *expected)
{
	teststr("ft_striteri");
	ft_striteri(s, f);
	funcresult(s, expected);	
}

void	test_ft_putchrptr_fd(void (*put)(char *, int), char *func,
		char *chrptr, int fd)
{
	teststr(func);	
	write(1, "\n\t", 2);
	put(chrptr, fd);
	write(1, "\n", 1);
}
void	test_ft_putchar_fd(char c, int fd)
{
	teststr("ft_putchar_fd");	
	write(1, "\n\t", 2);
	ft_putchar_fd(c, fd);
	write(1, "\n", 1);
}

void	test_ft_putnbr_fd(int nbr, int fd)
{
	teststr("ft_putnbr_fd");	
	write(1, "\n\t", 2);
	ft_putnbr_fd(nbr, fd);
	write(1, "\n", 1);
}

//------TEST COMPILATION--------//
void	test_part_two(void)
{
	char	*alphastr;
	char	*numstr;

	write(1, "\x1b[34m", 5); 
	write(1, "\nTESTING PART 2\n", 16);
	write(1, "\x1b[37m", 5); 
	alphastr = buildstr('A', 'Z');
	test_ft_substr(alphastr, 0, 4, "ABCD");
	free(alphastr);
	alphastr = buildstr('A', 'D');
	numstr = buildstr('0', '9');
	test_ft_strsomething(ft_strjoin, "ft_strjoin", alphastr, numstr,
			"ABCD0123456789");
	free(alphastr);
	free(numstr);
	alphastr = buildstr('0', '9');
	test_ft_strsomething(ft_strtrim, "ft_strtrim", alphastr, "01289", "34567");
	test_ft_strsomething(ft_strtrim, "ft_strtrim", alphastr, "9876", "012345");
	test_ft_strsomething(ft_strtrim, "ft_strtrim", "012310", "01", "23");
	free(alphastr);
	char **splittest;
	splittest = malloc(2 * sizeof(char *));
	splittest[0] = malloc(4 * sizeof(char));
	splittest[0] = "AAAA";
	splittest[1] = malloc(4 * sizeof(char));
	splittest[1] = "BBBB";
	test_ft_split("AAAAbCCCC", 'b', splittest);	
	free(splittest);
	alphastr = buildstr('1', '9');
	test_ft_itoa(123456789, alphastr);
	test_ft_itoa(0, "0");
	free(alphastr);
	test_ft_strmapi("AAAA", charplusint, "ABCD");
	alphastr = buildstr('A', 'F');	
	test_ft_striteri(alphastr, strplusint, "ACEGIK");
	free(alphastr);
	test_ft_putchar_fd('c', 1);
	test_ft_putchrptr_fd(ft_putstr_fd, "ft_putstr_fd", "str test", 1);
	test_ft_putchrptr_fd(ft_putendl_fd, "ft_putendl_fd", "endl test", 1);
	test_ft_putnbr_fd(1234, 1);
}
