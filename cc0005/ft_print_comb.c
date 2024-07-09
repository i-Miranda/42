#include <unistd.h>

void	checkformatch(char *previous, char *next, char prevmaxvalue, char nextminvalue);

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = '0';
	comb[1] = '1';
	comb[2] = '2';
	while(comb[0]+comb[1]+comb[2] != '7' + '8' + '9')
	{
		write(1,&comb,3);
		write(1, ", ", 3);
		(comb[2])++;
		checkformatch(&comb[2], &comb[1], '9', '1');
		checkformatch(&comb[1], &comb[0], '8', '0');
  }
	write(1,&comb,3);
}

void	checkformatch(char *previous, char *next, char prevmaxvalue, char nextminvalue)
{
	if(*previous >= prevmaxvalue)
	{
		if(*next > prevmaxvalue - 1)
			(*next) = nextminvalue;
		else
			(*next)++;
		*previous = (*next) + 1;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
