/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:09:24 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:42:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	found;
	int	len;
	char *str;

	i = 0;
	found = -1;
	len = (int)ft_strlen(s);
	str = (char *)s;
	while (i <= len)
	{
		if (str[i] == c)
			found = i;
		i++;
	}
	if (found != -1)
		return (&str[found]);
	return (NULL);
}
