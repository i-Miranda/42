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

int ft_iterative_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    int result;

    result = 1;
    while (nb > 0)
    {
        result *= nb;
        nb--;
    }
    
    return (result);
}

int main(void)
{
    write(1, "5 factorial is: ", 16);
    ft_putnbr(ft_iterative_factorial(5));
    write(1, "\n", 1);
    write(1, "0 factorial is: ", 16);
    ft_putnbr(ft_iterative_factorial(0));
    write(1, "\n", 1);
    write(1, "-10 factorial is: ", 18);
    ft_putnbr(ft_iterative_factorial(-10));
    write(1, "\n", 1);
}
