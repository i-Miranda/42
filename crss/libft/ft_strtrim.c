/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:09:27 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:42:21 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = (int)ft_strlen(s1);
	while (ft_strchr(set, s1[start]) != NULL && start < end)
		start++;
	while (ft_strchr(set, s1[end]) != NULL && end > 0)
		end--;
	str = malloc((end - start) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}
