#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (int)dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}	
	return (ft_strlen(dst));
}
