#include <unistd.h>

int isinrange(int *nbr, int min, int max)
{
	if(!(&min <= nbr && &max <= nbr))
		write(1, "Value is not of range integer", 29);
	return(&min <= nbr && &max <= nbr);
}

int checkfornegative(int *nbr)
{
	char neg;

	neg = '-';
	if (*nbr < 0)
	{
		write(1, &neg, 1);
		*nbr *= -1;
	} 
	return (*nbr);
}

int		getsingledigit(int nnbr, int *nbr, int n)
{
		char itoc;
		int div;
		int mod;

		itoc = '0';
		if (nnbr >= n)
		{
			mod = nnbr % n;
			div = nnbr / n;
			itoc = div + itoc;
			write(1, &itoc, 1);
			return(mod);
		}
		else if (nnbr < *nbr)
			write(1, &itoc, 1);
		return (nnbr);
}

void	ft_putnbr(int *nbr)
{
		char newline;
		int nnbr;

		newline = '\n';
		nnbr = *nbr;
		if(!isinrange(nbr, -2147483648, 2147483647))
			return;
		nnbr = checkfornegative(nbr);
		nnbr = getsingledigit(nnbr, nbr, 1000000000);
		nnbr = getsingledigit(nnbr, nbr, 100000000);
		nnbr = getsingledigit(nnbr, nbr, 10000000);
		nnbr = getsingledigit(nnbr, nbr, 1000000);
		nnbr = getsingledigit(nnbr, nbr, 100000);
		nnbr = getsingledigit(nnbr, nbr, 10000);
		nnbr = getsingledigit(nnbr, nbr, 1000);
		nnbr = getsingledigit(nnbr, nbr, 100);
		nnbr = getsingledigit(nnbr, nbr, 10);
		nnbr = getsingledigit(nnbr, nbr, 1);
		write(1, &newline, 1);
}

int main (void)
{
	int *nbr;
	int num;

	num = 5742;
	nbr = &num;
	ft_putnbr(nbr);
	num = -50000;
	ft_putnbr(nbr);
	num = 50000;
	ft_putnbr(nbr);
	num = -500009911;
	ft_putnbr(nbr);
	num = 500009911;
	ft_putnbr(nbr);
	num = 'b';
	ft_putnbr(nbr);
}
