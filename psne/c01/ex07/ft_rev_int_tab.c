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

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = 0;
	size -= 1;
	while (i < size / 2)
	{
		if (tab[size] != '\0')	
		{
			temp = tab[i];
			tab[i] = tab[size];
			tab[size] = temp;
		}
		i++;
		size--;
	}
}

int	main(void)
{
	int tab1[7] = {1, 2, 3, 4, 5, 6, '\0'};
	int tab2[8] = {1, 2, 3, 4, 5, 6, 7, '\0'};
	int i;

	i = 0;
	write(1, "tab1 : ", 7);
	while (tab1[i] != '\0')
	{
		ft_putnbr(tab1[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "tab1 after rev : ", 18);
	ft_rev_int_tab(tab1, 6);
	while (tab1[i] != '\0')
	{
		ft_putnbr(tab1[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "tab2 : ", 7);
	while (tab2[i] != '\0')
	{
		ft_putnbr(tab2[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "tab2 after rev : ", 18);
	ft_rev_int_tab(tab2, 7);
	while (tab2[i] != '\0')
	{
		ft_putnbr(tab2[i]);
		i++;
	}
	write(1, "\n", 1);
}
