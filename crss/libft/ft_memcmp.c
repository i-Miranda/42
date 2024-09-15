#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n && ((unsigned char *)s1)[i] != '\0')
	{
	 	if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			break;
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
