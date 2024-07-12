#include <unistd.h>

//int buildarray(int *arr, int n, int value)
//{
//	int bldint[n][value];
//	int counter;
//
//	while (n < 10)
//	{
//		counter = 0; 
//		while (counter < n * 10)
//		{
//			bldint[n][counter] = counter;
//		}
//		n--;
//	}
//}

void printpattern(int itoc, int n)
{
	char	prntchr;
	int		counter;	

	counter = 0;
	while (counter < 10)
	{
		prntchr = itoc + '0';
		counter++;
	}
	write(1, &prntchr, n);
}

void ft_print_combn(int n)
{
	int	prntint;

	prntint = n;
	while ((0 < n) && (n < 10))
	{
		printpattern(prntint, n); 
		n--;
	}
}

int main(int argc, char **argv) 
{
	int n;
	n = (**argv) - '0';
	ft_print_combn(n);
}
