#include <unistd.h>
#include <stdio.h>

void	ft_print_hexvalue(int decval, int i)
{
	int		mod[2];
	char	hexval;
	
	if (decval == 0)
		write(1, "0", 1);
	while (decval != 0)	
	{
		mod[i] = decval % 16;
		decval = decval / 16;
		if (decval == 0 && i == 0)
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

void	ft_print_substr(char *str, unsigned int length, unsigned int index)
{
	unsigned int	j; 

	j = 0;
	while (j < 16 && index + j < length)
	{
		if (str[index + j] <= 31)
			write(1, ".", 1);
		else
			write(1, &str[index + j], 1);
		j++;
	}
}

void	ft_print_substr_hexval(char *str, unsigned int length,
		unsigned int index)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (index + j < length)
			ft_print_hexvalue(str[index + j], 0); 
		else
			write(1, "  ", 2);
		if ((index + j) % 2 != 0)
			write(1, " ", 1);
		j++;
	}
}

//This isn't working yet
void	ft_print_memaddr(void *addr)         
{
	int	j;
	unsigned char	*uchar_addr;

	j = 7;
	uchar_addr = (unsigned char *)&addr;
	while (j > 0)
	{
		if (uchar_addr[j] != '\0')
			ft_print_hexvalue(uchar_addr[j], 0);
		else
			write(1, "00", 2);
		j--;
	}
} 

void	*ft_print_memory(void *addr, unsigned int size)
{
	if (size > 0)
	{
		unsigned int	i;
		unsigned int	j;
		char			*chr_addr;

		i = 0;
		chr_addr = (char *)addr;
		while(i < size)
		{
			ft_print_memaddr(addr);
			write(1, ": ", 2);
			ft_print_substr_hexval(chr_addr, size, i);
			ft_print_substr(chr_addr, size, i);
			write(1, "\n", 1);
			i += 16;	
		}
		printf("%p", &addr);
	}
	return (addr);
}

int	main(void)
{
	char test[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut"
		" faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	ft_print_memory(test,sizeof(test));
	return (0);
}
