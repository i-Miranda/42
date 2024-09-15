#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = malloc(ft_strlen(s) * sizeof(char));
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
