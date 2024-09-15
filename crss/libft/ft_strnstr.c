#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i <= (int)len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < (int)len)		
		{
			if (haystack[i + j] == '\0' && needle[j] == '\0')
				return (&((char *)haystack)[i]);
			j++;
		}
		if (needle[j] != '\0')
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}
