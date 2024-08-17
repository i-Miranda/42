#include <unistd.h>

void	ft_print_hexvalue(int decval)
{
	int		div;
	int		i;
	int		mod[2];
	char	hexval;
	
	i = 0;
	div = decval;
	if (div == 0)
		write(1, "0", 1);
	while (div != 0)	
	{
		mod[i] = div % 16;
		div = div / 16;
		if (div == 0 && i == 0)
			mod[i + 1] = 0;
		i++;
	}
	while (i >= 0)
	{
		if (mod[i] >= 10 && mod[i] <= 15)
			mod[i] += 39;
		hexval = mod[i] + '0';
		write(1, &hexval, 1);
		i--;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31) 
		{
			write(1, "\\", 1);
			ft_print_hexvalue(str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	char test[] = "Coucou\ntu vas bien?";

	ft_putstr_non_printable(test);
	return (0);
}
