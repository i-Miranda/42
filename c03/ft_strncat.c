#include <unistd.h>


unsigned int	ft_strlen(char *str)
{
	unsigned int	i;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{	
	unsigned int dest_l;
	unsigned int src_l;
	unsigned int i;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (dest_l + src_l < nb)
	{
		while(src[i] != '\0')
		{
			dest[dest_l + i] = src[i];		
			i++;
		}
		dest[dest_l + i] = '\0';
	}
	return (dest);
}
