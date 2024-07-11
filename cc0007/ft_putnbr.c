#include <unistd.h>

int		getsingledigit(int *nbr, int n)
{
		char itoc;
		int div;
		int mod;

		itoc = '0';
		if (*nbr >= n)
		{
			mod = *nbr % n;
			div = *nbr / n;
			itoc = div + itoc;
			write(1, &itoc, 1);
			return(mod);
		}
		return (*nbr);
}

void	ft_putnbr(int *nbr)
{
		const int imax = 32488;
		char neg;

		neg = '-';
		if(*nbr < imax * - 1 || *nbr > imax)
		{
			write(1, "Value is not of range integer", 28);
			return;
		}
		if (imax > 0)
		{
			write(1, &neg, 1);
			*nbr *= -1;
		}
		*nbr = getsingledigit(nbr, 10000);
		*nbr = getsingledigit(nbr, 1000);
		*nbr = getsingledigit(nbr, 100);
		*nbr = getsingledigit(nbr, 10);
		*nbr = getsingledigit(nbr, 1);
}

int main (void)
{
	int *nbr;
	int num;

	num = -5742;
	nbr = &num;
	ft_putnbr(nbr);
}
