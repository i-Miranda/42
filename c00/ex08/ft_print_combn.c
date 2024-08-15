#include <unistd.h>

void	ft_putnbr(int nb)
{
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

int	ft_print_digit(int i, int j)
{
	char	digit;
	int		remainder;

	if (i == j)
		j++;
	digit = (j / 10) + '0';
	remainder = (i % 10);
	write(1, &digit, 1);
	return(remainder);
}

int	ft_ten_pow_n(int n)
{
	int	i;

	i = 1;
	while(n > 0)
	{
		i *= 10; 
		n--;
	}
	return (i);
}

void	ft_print_combn(int n)
{
	int	i;

	i = ft_ten_pow_n(n - 2);
	if (0 < n && n < 10)
	{
		while (i < ft_ten_pow_n(n))
		{
			ft_putnbr(i);
			if (i != ft_ten_pow_n(n) - 1)
				write(1, ", ", 2);
			i++;
		}
	}
	else
		return;
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}
