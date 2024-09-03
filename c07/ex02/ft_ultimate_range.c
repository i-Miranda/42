#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int i;
	int atoi[2];

	i = 0;
	atoi[0] = 0;
	atoi[1] = 1;
	while ((str[i] != '\0') && (str[i] == ' '))
		i++;
	while ((str[i] != '\0') && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			atoi[1] *= -1;	
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		atoi[0] = atoi[0] * 10 + str[i] - '0';
		i++;
	}
	return (atoi[0] * atoi[1]);	
}

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

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		range = malloc((max - min) * sizeof(int));
		while (i < (max - min))
		{
			*range = malloc(2 * sizeof(int));
			range[i][1] = min + i;
			range[i][0] = &range[i][1];
			i++;
		}
	}
	return (sizeof(*range));
}

int	main(int argc, char *argv[])
{
	int **range;
	int	i;
	int	min;
	int	max;
	
	min = ft_atoi(argv[1]);
	ft_putnbr(min);
	write(1, "\n", 1);
	max = ft_atoi(argv[2]);
	ft_putnbr(max);
	write(1, "\n", 1);
	ft_ultimate_range(range, min, max);
	i = 0;
	while (i < max - min)
	{
		ft_putnbr(range[i][0]);
		write (1, ", ", 2);
		ft_putnbr(range[i][1]);
		write(1, "\n", 1);
		i++;
	}
}
