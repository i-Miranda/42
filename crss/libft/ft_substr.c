#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char 			*substr;
	unsigned int	i;

	substr = malloc(len * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && substr[i] != '\0')
	{
		substr[i] = s[start + i];	
		i++;
	}
	return (substr);
}
