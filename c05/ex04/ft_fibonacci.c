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

int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    else if (index < 2)
        return (index);
    else
        return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int main(void)
{
    ft_putnbr(ft_fibonacci(9));
    return (0);
}
