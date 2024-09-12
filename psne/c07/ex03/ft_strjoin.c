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

char	*ft_str_malloc(int size, char *dest, char **src)
{
	int	i;
	int	strslen;

	i = 0;
	strslen = 0;
	while (i < size)
	{
		strslen += ft_strlen(src[i]);
		i++;
	}
	dest = malloc(strslen * sizeof(char));
	return (dest);
}

int	ft_appendstr(char *str, int position, char *str2)
{
	int	i;

	i = 0;
	while (str2[i] != '\0')
	{
		str[position] = str2[i];
		position++;
		i++;
	}
	return (position);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*str;

	if (size == 0)
	str = malloc(sizeof(char *));	
	else
	{
		str = ft_str_malloc(size, str, strs);
		i = 0;
		j = 0;
		while (i < size)
		{
			j = ft_appendstr(str, j, strs[i]);
			j = ft_appendstr(str, j, sep);
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
	while (i <= argc - 2)
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
	free(str);
	free(strs);
}
