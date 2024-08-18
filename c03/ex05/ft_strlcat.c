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

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}	

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_len;
	int	src_len;
	int	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);	
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int nbr;

		ft_putstr(argv[1]);
		write(1, "\n", 1);
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		nbr = ft_strlcat(argv[1], argv[2], 5);
		write(1, "\n", 1);
		ft_putstr(argv[1]);
		write(1, "\n", 1);
		ft_putnbr(nbr);
		write(1, "\n", 1);
	}
	return (0);
}
