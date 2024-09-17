/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:46 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/17 12:48:38 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcount(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		len;
	char	**strarray;

	count = 0;
	i = 0;
	while (s[i] != '\0')
		count += ft_charcount(&s[i++], c);
	strarray = malloc((count + 2) * sizeof(char *));
	if (strarray == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (i < count)
	{
		strarray[i] = ft_substr(s, len, (size_t)ft_charcount(&s[len], c));
		len = ft_charcount(&s[len], c);
		if (strarray[i] == NULL)
			free(strarray[i]);
		i++;
	}
	strarray[i] = NULL;
	return (strarray);
}
