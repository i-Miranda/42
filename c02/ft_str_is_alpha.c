#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int i;
	
	i = 0;
	if (str[0] == '\0') 
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') ||
			(str[i] >= 'A' && str[i] <= 'Z'))
			i++;
		else
			return(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int error;
	char check;

 	error = 0;
	if(argc == 2)
		error = ft_str_is_alpha(argv[1]);
	else
		error = ft_str_is_alpha("");
		check = error + '0';	
		write(1, &check, 1);
	return (error);
}
