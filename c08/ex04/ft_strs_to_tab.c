#include "ft_strs_to_tab.c"

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

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	
}

int		main(int argc, char *argv[])
{
	t_stock_str tsr;
	int			i;

	tsr = ft_strs_to_tab(argc, argv);
	ft_putnbr(tsr.size);	
	write(1, "\n", 1);
	i = 0;
	while (tsr->str[i] != '\0')
	{
		write(1, &tsr->str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	while (tsr->copy[i] != '\0')
	{
		write(1, &tsr->copy[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
