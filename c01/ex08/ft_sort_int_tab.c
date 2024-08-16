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

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int temp;

	while (size > 0)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i + 1] != '\0' && tab[i] > tab[i + 1])	
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}

int	main(void)
{
	int tab1[5] = {8, 4, 9, 1, '\0'};
	int tab2[6] = {3, 2, 7, 1, 6, '\0'};
	int tab3[11] = {3, 2, 7, 1, 6, 9, 8, 4, 0, 5, '\0'};
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
	write(1, "tab1 after sort : ", 18);
	ft_sort_int_tab(tab1, 4);
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
	write(1, "tab2 after sort : ", 18);
	ft_sort_int_tab(tab2, 5);
	while (tab2[i] != '\0')
	{
		ft_putnbr(tab2[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "tab3 : ", 7);
	while (tab3[i] != '\0')
	{
		ft_putnbr(tab3[i]);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	write(1, "tab3 after sort : ", 18);
	ft_sort_int_tab(tab3, 10);
	while (tab3[i] != '\0')
	{
		ft_putnbr(tab3[i]);
		i++;
	}
	write(1, "\n", 1);
}
