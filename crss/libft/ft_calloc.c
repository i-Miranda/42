#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*voidptr;

	voidptr = malloc(count * size);
	if (voidptr == NULL)
		return (NULL);
	ft_bzero(voidptr, count * size);
	return (voidptr);
}
