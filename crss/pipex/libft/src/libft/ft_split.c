/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:46 by ivmirand          #+#    #+#             */
/*   Updated: 2025/02/12 15:04:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_initialize(const char *str, size_t *s_i, int *arr_i, int *start)
{
	if (str == NULL)
		return (-1);
	*s_i = 0;
	*arr_i = 0;
	*start = -1;
	return (0);
}

static char	*build_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(end - start + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	return (word);
}

static int	ft_word_count(const char *str, char c)
{
	int	count;
	int	split;

	count = 0;
	split = 0;
	while (*str)
	{
		if (*str != c && split == 0)
		{
			split = 1;
			count++;
		}
		else if (*str == c)
			split = 0;
		str++;
	}
	return (count);
}

static void	*ft_freeptr(char **strarray, int count)
{
	while (count--)
		free(strarray[count]);
	free(strarray);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strarray;
	size_t	s_i;
	int		arr_i;
	int		start;

	if (ft_initialize(s, &s_i, &arr_i, &start) == -1)
		return (NULL);
	strarray = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!strarray)
		return (NULL);
	while (s_i <= ft_strlen(s))
	{
		if (s[s_i] != c && start < 0)
			start = s_i;
		else if ((s[s_i] == c || s_i == ft_strlen(s)) && start >= 0)
		{
			strarray[arr_i] = build_word(s, start, s_i);
			if (!(strarray[arr_i]))
				return (ft_freeptr(strarray, arr_i));
			start = -1;
			arr_i++;
		}
		s_i++;
	}
	return (strarray);
}
