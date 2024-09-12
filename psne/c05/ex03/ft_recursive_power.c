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

int ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    return nb * ft_recursive_power(nb, power - 1);
}

int main(void)
{
    write(1, "5 to the power of 2 is: ", 24);
    ft_putnbr(ft_recursive_power(5, 2));
    write(1, "\n", 1);
    write(1, "10 to the power of 0 is: ", 25);
    ft_putnbr(ft_recursive_power(10, 0));
    write(1, "\n", 1);
    write(1, "2 to the power of 4 is: ", 25);
    ft_putnbr(ft_recursive_power(2, 4));
    write(1, "\n", 1);
}
