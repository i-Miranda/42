#include <unistd.h>

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0';
	second = '0';
	third = '0';
	while (first < '8')
	{
		second = first + 1;
		while (second < '9')
		{
			third = second + 1;
			while (third < ':')
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				if (first + second + third != '7' + '8' + '9')
					write(1, ", ", 1);
				third++;
			}
			second++;
		}
		first++;	
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
