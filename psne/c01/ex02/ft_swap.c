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

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int one;
	int two;

	one = 1;
	two = 2;
	write(1, "one is ", 7);
	ft_putnbr(one);
	write(1, "\n", 1);
	write(1, "two is ", 7);
	ft_putnbr(two);
	write(1, "\n", 1);
	ft_swap(&one, &two);
	write(1, "one is ", 7);
	ft_putnbr(one);
	write(1, "\n", 1);
	write(1, "two is ", 7);
	ft_putnbr(two);
	write(1, "\n", 1);
}
