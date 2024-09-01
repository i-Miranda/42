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

int ft_find_next_prime(int nb)
{
    int i;

    i = 2;
    if (nb <= 1)
        return (ft_find_next_prime(nb + 1));
    while (i <= nb / 2)
    {
        if (nb % i == 0)
            return (ft_find_next_prime(nb + 1));
        else
            i++;
    }
    return (nb);
}

int main(void)
{
    ft_putnbr(ft_find_next_prime(0));
    write(1, "\n", 1);
    ft_putnbr(ft_find_next_prime(3));
    write(1, "\n", 1);
    ft_putnbr(ft_find_next_prime(4));
    write(1, "\n", 1);
    ft_putnbr(ft_find_next_prime(8));
    write(1, "\n", 1);
}
