/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/25 16:30:12 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != NULL && start < end)
		start++;
	while (ft_strrchr(set, s1[end]) != NULL && end > 0)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
