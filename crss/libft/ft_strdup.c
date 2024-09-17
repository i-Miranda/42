/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:53 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:47:05 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	str = malloc(len * sizeof(char));
	if (ft_strlen(str) != len)
		return (NULL);
	while (i < (int)len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
