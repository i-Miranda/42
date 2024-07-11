#include <unistd.h>

void	checkforten(char *previous, char *next, int start, char *tick)
{
	if (*previous > '9')
	{
		*previous = *tick + start;
		(*next)++;
		(*tick)++;
			
	}
}

void	ft_print_comb(void)
{
	char	comb[7];

	comb[0] = '0';
	comb[1] = '1';
	comb[2] = '2';
	comb[3] = ',';
	comb[4] = ' ';
	comb[5] = '1';	 
	comb[6] = '1';	 
	while(comb[0] < '7')
	{
		if(comb[2] != comb[1] && comb[1] != comb[0] && comb[0] != comb[2])
			write(1,&comb,5);
		(comb[2])++;
		checkforten(&comb[2], &comb[1], 2, &comb[6]);
		checkforten(&comb[1], &comb[0], 1, &comb[5]);
	}
		write(1,&comb,3);
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
