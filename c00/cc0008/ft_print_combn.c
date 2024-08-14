#include <unistd.h>
int	exponent(int value, int n)
{
	int output;

	output = value;
	while (n > 0)
	{
		output *= value;
		n--;
	}
	return (output);
}

void	printpattern(int n, int inputvalue)
{
	char prntchr[9];
	int		counter;
	int		divisor;

	counter = 0;
	while (counter < n) 
	{
		divisor = exponent(inputvalue , n);	
		prntchr[counter] = (inputvalue / divisor) - '0';
		counter++;
	}
	write(1, prntchr, n);
	write(1, ", ", 2);
}

int	totalpossible(int n)
{
	int	possible;
	int	counter;
	
	possible = n;
	counter = 0;
	while (counter > 1)
	{
		possible *= n - counter;
		counter++;
	}
	return (possible);
}

void	doesitrepeat(int n, int possible)
{
	int counter;
	int i;
	int j;

	counter = 0;
	while (counter < possible)
	{
		printpattern(n,possible);
		counter++;
	}
}

void ft_print_combn(int n)
{
	int	possiblen;

	if ((0 < n) && (n < 10))
	{
		possiblen = totalpossible(n);
		doesitrepeat(n, possiblen);
	}
}

int main(int argc, char **argv) 
{
	int n;
	
	if (argc == 2)
	{
		n = (*argv[1]) - '0';
		ft_print_combn(n);
		return (0);
	} 
	write(1, "-ERROR 404-: Insert an argument of value 0 - 9\n\0", 48);
	return (1);
}
