/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:46 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/28 16:13:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *str, char c)
{
	int		i;
	int		chr_match;
	int		len;
	int		word_count;

	i = 0;
	chr_match = 0;
	word_count = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != c && chr_match == 0)
		{
			word_count++;
			chr_match = 1;
		}
		else if (str[i] == c)
			chr_match = 0;
		i++;
	}
	return (word_count);
}

static void	*ft_freeptr(char **strarray, int count)
{
	while (count--)
		free(strarray[count]);
	free(strarray[count]);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	len;
	char	**strarray;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = 0;
	len = ft_strlen(s);
	while (i++ < len)
		count += ft_wordcount(&s[i], c);
	strarray = ft_calloc(count + 1, sizeof(char *));
	if (strarray != NULL)
		return (strarray);
	i = 0;
	while (i++ <= len)
	{
		strarray[i] = ft_substr(s, len, ft_wordcount(&s[len], c));
		if (strarray[i] == NULL)
			strarray = ft_freeptr(strarray, i);
		len += ft_wordcount(&s[len], c);
	}
	return (strarray);
}
