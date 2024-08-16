#include <unistd.h>

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

int	main(void)
{
	char dest[] = "";
	char src[] = "new string\0";

	ft_strcpy(dest, src);
	write(1, "dest now is: ", 13);
	ft_putstr(dest);	
	write(1, "\n", 1);
}
