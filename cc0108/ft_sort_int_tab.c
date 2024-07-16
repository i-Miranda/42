int	pow(int value, int exp)
{
	int counter;
	int newint;

	counter = 0;
	if (exp == 0)
		return (1);
	newint = value;
	while (counter < exp)
	{
		newint *= value;
		counter++;
	}
	return (value);
}
int	atoi(char *str)
{
	int	counter;
	int newint;

	counter = 0;
	newint = 0;
	while ((str[counter] != '\0') &&
		 (str[counter] >= '0') && (str[counter] <= '9'))
	{
		if (counter > 0)
		{
			
		}
		while ()
		{
			newint += (str[counter] - '0'); 	
		}
		counter++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (tab[size - i] != '\0')
	{
		if ((i < 0) && (tab[size - i] < tab[size - i - 1))
		{
			tab[size - i - 1] = tab[size - i] ^ tab[size - i - 1];
			tab[size - i] = tab[size - i - 1] ^ tab[size - i];
			tab[size - i - 1] = tab[size - i] ^ tab[size - i - 1];
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int counter; 
	int *intarray;

	counter = 0;
	while (counter < argc)
	{
		counter++;		
	}
}
