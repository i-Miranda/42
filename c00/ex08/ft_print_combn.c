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
	if (nb >= 10)
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

void	ft_print_combn(int n)
{
	int	i;

	i = 0;
	if (0 < n && n < 10)
	{
		while (i < n * 10)
		{
			ft_putnbr(i);
			if (i != (n * 10) - 1)
				write(1, ", ", 1);
			i++;
		}
	}
	else
		return;
}

int	main(void)
{
	ft
}
