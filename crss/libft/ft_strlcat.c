#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int i;
	int	dst_len;
	int	src_len;

	i = 0;
	dst_len = (int)ft_strlen(dst);
	src_len = (int)ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (i < (int)dstsize - 1 && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}