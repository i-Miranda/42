/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:46 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/28 11:07:58 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_charcount(char const *str, char c)
{
	int		i;
	char	*previous;
	int		len;
	size_t	word_count;

	i = 0;
	previous = 0;
	word_count = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == c && previous != (char *)&str[i])
		{
			word_count++;
			previous = (char *)&str[i];
		}
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;
	char	**strarray;

	if (s == NULL)
		return (NULL);
	count = 0;
	i = 0;
	len = ft_strlen(s);
	while (i++ < len)
		count += ft_charcount(&s[i], c);
	strarray = ft_calloc(count + 1, sizeof(char *));
	if (strarray != NULL)
		return (strarray);
	if (count == 0)
		strarray[0] = ft_strdup(s);
	else
	{
		i = 0;
		len = 0;
		while (strarray[i++] != NULL)
		{
			strarray[i] = ft_substr(s, len, ft_charcount(&s[len], c));
			if (strarray[i] == NULL)
				free(strarray[i]);
			len += ft_charcount(&s[len], c);
		}
	}
	return (strarray);
}
