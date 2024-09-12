#include <unistd.h>

void	ft_itoa(int nb, char *array, int i, int n)
{
	if (nb > n)
	{
		ft_itoa(nb / 10, array, i + 1, n);
		ft_itoa(nb % 10, array, i + 1, n);
	}
	else
	{
		array[i] = nb + '0';
	}
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
	int	j;
	char	array[9];

	j = 0;
	while (j < 9)
	{
		array[j] = '\0';
		j++;
	}
	i = 0;
	if (0 < n && n < 10)
	{
		while (i < ft_ten_pow_n(n))
		{
			j = n;
			ft_itoa(i, array, 0, 9);
			while (j >= 0)
			{ 
				if (array[j] != '\0')
					write(1, &array[j], 1);
				j--;
			}
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
