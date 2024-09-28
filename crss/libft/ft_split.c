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
	int	previous;
	int	word_count;

	i = 0;
	previous = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && previous != c)
			word_count++;
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		len;
	char	**strarray;

	if (s == NULL)
		return (NULL);
	count = 0;
	i = 0;
	while (s[i] != '\0')
		count += ft_charcount(&s[i++], c);
	strarray = ft_calloc(count + 1, sizeof(char *));
	if (strarray != NULL)
	{
		if (count == 0)
		{
			strarray[0] = ft_strdup(s);
			return (strarray);
		}
		i = 0;
		len = 0;
		while (strarray[i] != NULL)
		{
			strarray[i] = ft_substr(s, len, (size_t)ft_charcount(&s[len], c));
			len = ft_charcount(&s[len], c);
			if (strarray[i] == NULL)
				free(strarray[i]);
			i++;
		}
	}
	return (strarray);
}
