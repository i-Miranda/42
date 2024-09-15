
#include "libft.h"

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
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] != expected[i])
		{
			write(1, "FAIL\n", 5);
			return;
		}
		i++;
	}
	write(1, "PASS\n", 5);
}

//!---TESTS---!//

void	test_ft_issomething(int(*f)(int))
{
	int		i;
	int		fresult;
	char	results[127];
	char	expected[127];
	char	printchar;

	i = 0;
	while (i < 128)
	{
		printchar = i;	
		fresult = f(i);
		if (fresult != 0)
		{
			printchar = i;	
			write(1, &printchar, 1);
			write(1, "[TRUE]", 6);
			write(1, "\n", 1);
		}
		results[i] = fresult + '0';
		i++;
	}
	funcresult(results, expected);
}

int	main(void)
{
	system("cat libft.h");
	test_ft_issomething(ft_isalpha);
	test_ft_issomething(ft_isdigit);
	test_ft_issomething(ft_isalnum);
	test_ft_issomething(ft_isascii);
	test_ft_issomething(ft_isprint);
	test_ft_issomething(ft_tolower);
	test_ft_issomething(ft_toupper);
	return (0);
}
