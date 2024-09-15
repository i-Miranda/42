#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;

	i = 0;
	temp_src = src;	
	while (i < n)
	{
		dst[i] = temp_src[i];
		i++;
	}
	return (dst);		
}
