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

int ft_is_prime(int nb)
{
    int i;

    i = 2;
    if (nb <= 1)
        return (0);
    while (i <= nb / 2)
    {
        if (nb % i == 0)
            return (0);
        else
            i++;
    }
    return (1);
}

int main(void)
{
    ft_putnbr(ft_is_prime(0));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(1));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(2));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(3));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(4));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(5));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(6));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(7));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(8));
    write(1, "\n", 1);
    ft_putnbr(ft_is_prime(9));
    write(1, "\n", 1);
}
