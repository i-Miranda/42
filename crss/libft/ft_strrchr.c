#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int found;

	i = 0;
	found = -1;
	while (i <= len)
	{
		if (s[i] == c)
			found = i;
		i++;
	}
	if (found != -1)	
		return ((char *)&s[found]);
	return (NULL);
}
