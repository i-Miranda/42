#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size > 0)
	{
		unsigned int i;
		unsigned int j;
		char *chr_addr = addr;

		i = 0;
		while(i < size)
		{
			j = 0;
			while (j < 16)
			{
				ft_print_hexvalue(chr_addr[j]); 
				j++;
			}
			write(1, ": ", 2);
			j = 0;
			while (j < 16)
			{
				if (i + j < size)
					ft_print_hexvalue(chr_addr[i + j]); 
				else
					write(1, "  ", 2);
				if ((i + j) % 2 != 0)
					write(1, " ", 1);
				j++;
			}
			j = 0;
			while (j < 16 && i + j < size)
			{
				if (chr_addr[i + j] <= 31)
					write(1, ".", 1);
				else
					write(1, &chr_addr[i + j], 1);
				j++;
			}
			write(1, "\n", 1);
			i = i + 16;	
		}
	}
	return (addr);
}

int	main(void)
{
	char test[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut"
		" faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
	ft_print_memory(test, ft_strlen(test) + 1);
	return (0);
}
