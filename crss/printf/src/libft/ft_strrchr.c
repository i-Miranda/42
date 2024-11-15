/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:09:24 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/28 23:03:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	chr;

	chr = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == chr)
		return ((char *)&s[i]);
	return (NULL);
}
