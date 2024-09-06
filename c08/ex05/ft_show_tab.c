#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(src[i] != '\0') 
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
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

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tsr;
	int			i;

	i = 0;
	tsr = malloc((ac) * sizeof(t_stock_str));
	if (tsr == NULL)
		return (tsr);
	while (i < ac - 1)	
	{	
		tsr[i].size = ft_strlen(av[i + 1]);	
		tsr[i].str = malloc(tsr[i].size * sizeof(char));	
		tsr[i].str = ft_strcpy(tsr[i].str, av[i + 1]);
		tsr[i].copy = malloc(ft_strlen(tsr[i].str) * sizeof(char));	
		tsr[i].copy = ft_strcpy(tsr[i].copy, tsr[i].str);
		i++;
	}
	tsr[i].size = 0;	
	tsr[i].str = 0;	
	tsr[i].copy = 0;
	return (tsr);	
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	t_stock_str *tsr;
	int			i;

	tsr = ft_strs_to_tab(argc, argv);
	write(1, "\n", 1);
	ft_show_tab(tsr);
	i = 0;
	while (i < argc)
	{
		free(tsr[i].str);
		ft_putnbr(i);
		write(1, " str freed.\n", 12);
		free(tsr[i].copy);
		ft_putnbr(i);
		write(1, " copy freed.\n", 13);
		i++;
	}
	free(tsr);
	write(1, "tsr freed.\n", 11);
	return (0);
}
