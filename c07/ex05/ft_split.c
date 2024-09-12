#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_char_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**strarray;
	int		i;	
	int		j;	
	int		k;	
	int		word_building;

	i = 0;
	j = 0;
	k = 0;
	word_building = 0;
	while (str[i] != '\0')
	{
	 	if (ft_char_is_sep(str[i], charset) && word_building)
		{
			word_building = 0;
			j++;
			k = 0;
		}
		else if (ft_char_is_sep(str[i], charset) && !word_building)
			word_building = 1;
		else
		{
			strarray[j][k] = str[i];
			k++;
		}
		i++;
	}
	strarray[i] = 0;
	return (strarray);
}

int		main(int argc, char *argv[])
{
	ft_split(argv[1], argv[2]);
	return (0);
}
