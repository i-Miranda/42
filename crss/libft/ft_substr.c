/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:09:30 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:41:44 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	substr = malloc(len * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && substr[i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
