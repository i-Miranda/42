#include <unistd.h>

void	ft_putnbr(int nb)
{		
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb = nb + '0';
		write(1, &nb, 1);
	}
}

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

int	main(void)
{
	int *ptra;
	int **ptrb;
	int ***ptrc;
	int ****ptrd;
	int *****ptre;
	int ******ptrf;
	int *******ptrg;
	int ********ptrh;
	int *********ptrnbr;
	int nbr;

	nbr = 0;
	ptra = &nbr;
	ptrb = &ptra;
	ptrc = &ptrb;
	ptrd = &ptrc;
	ptre = &ptrd;
	ptrf = &ptre;
	ptrg = &ptrf;
	ptrh = &ptrg;
	ptrnbr = &ptrh;
	write(1, "num is ", 7);
	ft_putnbr(*********ptrnbr);
	write(1, "\n", 1);
	ft_ultimate_ft(ptrnbr);
	write(1, "num is ", 7);
	ft_putnbr(*********ptrnbr);
	write(1, "\n", 1);
	return (0);
}
