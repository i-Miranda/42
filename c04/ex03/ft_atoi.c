#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

int	ft_atoi(char *str)
{
	int atoi[2];

	atoi[0] = 0;
	atoi[1] = 1;
	while ((*str != '\0') && (*str++ == ' '));
	while ((*str != '\0') && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			atoi[1] *= -1;	
	while ((*str != '\0') && (*str >= '0' && *str <= '9'))
		atoi[0] = atoi[0] * 10 + *str++ - '0';
	return (atoi[0] * atoi[1]);	
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	test;

		test = ft_strlen(argv[1]);
		write(1, argv[1], test);
		write(1, "\n", 1);
		test = ft_atoi(argv[1]);
		ft_putnbr(test);
	}
	else
		write(1, "Please input ONE string.", 24);
	return (0);
}
