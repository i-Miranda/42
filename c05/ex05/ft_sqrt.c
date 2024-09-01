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

int ft_sqrt(int nb)
{
    int counter;
    int result;

    counter = 1;
    result = 3;
    while (counter < result)
    {
        result = nb / counter;
        if (result != counter)
            counter++;
    }
    if (result * counter == nb)
        return (result);
    else
        return (0);
}

int main(void)
{
    ft_putnbr(ft_sqrt(25));
    write(1, "\n", 1);
    ft_putnbr(ft_sqrt(27));
    write(1, "\n", 1);
}
