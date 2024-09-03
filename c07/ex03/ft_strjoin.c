#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	int		strslen;
	char	*str;

	i = 0;
	k = 0;
	strslen = 0;
	if (size == 0)
	{
		str = malloc(5 * sizeof(char));	
	}
	else
	{
		while (i < size)
		{
			strslen += ft_strlen(strs[i]);
			i++;
		}
		str = malloc(strslen * sizeof(char));
		while (i < size)
		{
			j = 0;
			while (strs[i][j] != '\0')
			{
				str[k] = strs[i][j];
				k++;
				j++;
			}
			j = 0;
			while (sep[j] != '\0')
			{
				str[k] = sep[j]; 
				k++;
				j++;
			}
			i++;		
		}
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	int	i;
	char	**strs;
	char	*str;

	i = 1;
	strs = malloc((argc - 2) * sizeof(char*));
	while (i < argc - 2)
	{
		strs[i - 1] = malloc(ft_strlen(argv[i]) * sizeof(char));
		strs[i - 1] = argv[i];
		i++;
	}
	str = ft_strjoin(argc - 2, strs, argv[argc - 1]); 
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
