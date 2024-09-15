#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1 != '\0')
		str++ = s1++;
	while (s2 != '\0')
		str++ = s2++;
	return (str);
}
