#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void    ft_check_for_negative(int *nb, char *base)
{
    int i;
    int result;

    i = 0;
    result = 0;
    if (*nb < 0)
    {
        *nb *= -1;
        if (ft_strlen(base) == 10)
            write(1, "-", 1);
        else
        {
            result = 1 << 31;
            result -= 1;
            *nb = ~*nb & result;
            *nb ^= 1;
        }
    }
}

void	ft_putnbr_base(int nb, char *base)
{		
    int     i;

    i = 0;
	if (ft_check_base(base) == 1)
		return;
    ft_check_for_negative(&nb, base);
    if (nb > ft_strlen(base) - 1)
    {
        ft_putnbr_base(nb / ft_strlen(base), base);
        ft_putnbr_base(nb % ft_strlen(base), base);
    }
    else
        write(1, &base[nb], 1);
}

int	main(void)
{
    write(1, "Testing 101", 11);
    write(1, "\n\tin decimal: ", 14);
	ft_putnbr_base(101, "0123456789");
    write(1, "\n\tin binary: ", 13);
	ft_putnbr_base(101, "01");
    write(1, "\n\tin hexadecimal: ", 18);
	ft_putnbr_base(101, "0123456789abcdef");
    write(1, "\n\tin octal: ", 12);
	ft_putnbr_base(101, "01234567");
	write(1, "\n", 1);
    write(1, "Testing -101", 12);
    write(1, "\n\tin decimal: ", 14);
	ft_putnbr_base(-101, "0123456789");
    write(1, "\n\tin binary: ", 13);
	ft_putnbr_base(-101, "01");
    write(1, "\n\tin hexadecimal: ", 18);
	ft_putnbr_base(-101, "0123456789abcdef");
    write(1, "\n\tin octal: ", 12);
	ft_putnbr_base(-101, "01234567");
	write(1, "\n", 1);
    write(1, "Testing 2147483647", 18);
    write(1, "\n\tin decimal: ", 14);
	ft_putnbr_base(2147483647, "0123456789");
    write(1, "\n\tin binary: ", 13);
	ft_putnbr_base(2147483647, "01");
    write(1, "\n\tin hexadecimal: ", 18);
	ft_putnbr_base(2147483647, "0123456789abcdef");
    write(1, "\n\tin octal: ", 12);
	ft_putnbr_base(2147483647, "01234567");
	write(1, "\n", 1);
    write(1, "Testing -2147483648", 19);
    write(1, "\n\tin decimal: ", 14);
	ft_putnbr_base(-2147483648, "0123456789");
    write(1, "\n\tin binary: ", 13);
	ft_putnbr_base(-2147483648, "01");
    write(1, "\n\tin hexadecimal: ", 18);
	ft_putnbr_base(-2147483648, "0123456789abcdef");
    write(1, "\n\tin octal: ", 12);
	ft_putnbr_base(-2147483648, "01234567");
	write(1, "\n", 1);
}
