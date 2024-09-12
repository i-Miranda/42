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

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 10;
	b = 3;
	div = 0;
	mod = 42;
	write(1, "a is ", 5);
	ft_putnbr(a);
	write(1, "\n", 1);
	write(1, "b is ", 5);
	ft_putnbr(b);
	write(1, "\n", 1);
	write(1, "div is ", 7);
	ft_putnbr(div);
	write(1, "\n", 1);
	write(1, "mod is ", 7);
	ft_putnbr(mod);
	write(1, "\n", 1);
	ft_div_mod(a, b, &div, &mod);
	write(1, "a is ", 5);
	ft_putnbr(a);
	write(1, "\n", 1);
	write(1, "b is ", 5);
	ft_putnbr(b);
	write(1, "\n", 1);
	write(1, "div is ", 7);
	ft_putnbr(div);
	write(1, "\n", 1);
	write(1, "mod is ", 7);
	ft_putnbr(mod);
	write(1, "\n", 1);
}
