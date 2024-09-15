#include "libft.h"

static int	ft_intdigits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int	i;
	
	array = malloc(ft_intdigits(n) * sizeof(char));
	if (array == NULL)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		array[0] = '-';
		n *= 1;
	}
	i = 0;
	while (n >= 0)
	{
		array[i] = (n / 10) + '0';			
		n %= 10;
		i++;
	}
	return (array);
}
