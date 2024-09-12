#include <unistd.h>
void	ft_counter_to_comb(int counter)
{
	char comb[2];
	
	comb[0] = (counter / 10) + '0';
	comb[1] = (counter % 10) + '0';
	write(1, &comb[0], 1);
	write(1, &comb[1], 1);
}


void	ft_print_comb2(void)
{
	int		counter1;
	int		counter2;

	counter1 = 0;
	while (counter1 <= 98)
	{
		counter2 = counter1 + 1;
		while (counter2 <= 99)
		{
			ft_counter_to_comb(counter1);
			write(1, " ", 1);
			ft_counter_to_comb(counter2);
			if (counter1 != 98 && counter2 != 99)
				write(1, ", ", 2);
			counter2++;
		}
		counter1++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
