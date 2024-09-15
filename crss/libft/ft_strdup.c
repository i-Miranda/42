#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	str = malloc(len * sizeof(char));	
	if (ft_strlen(str) != len)
		return (NULL);
	while (i < (int)len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
