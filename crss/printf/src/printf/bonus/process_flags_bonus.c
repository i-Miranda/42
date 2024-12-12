/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:02:34 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 19:29:02 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

static void	rebuild_flags(char *c, char *flags, int	*m_zero, int *p_space)
{
	size_t	len;
	int		i;
	int		j;

	len = ft_strlen(c);
	i = 0;
	j = 0;
	flags = ft_calloc(len, sizeof(char));
	while (i < (int)len)
	{
		if (*m_zero == TRUE && c[i + j] == '0')
			j++;
		if (*p_space == TRUE && c[i + j] == ' ')
			j++;
		flags[i] = c[i + j];
		i++;
	}
	free(c);
}

char	*ft_find_flags(char *c)
{
	char	*flags;
	int		i;

	flags = NULL;
	i = 0;
	while (c[i] != 'c' && c[i] != 's' && c[i] != 'p' && c[i] != 'd'
		&& c[i] != 'i' && c[i] != 'u' && c[i] != 'x' && c[i] != 'X'
		&& c[i] != '%' && c[i] != '\0')
		i++;
	if (i <= 0)
		return (flags);
	flags = ft_calloc(i + 1, sizeof(char));
	if (!flags)
		return (flags);
	while (i-- > 0)
		flags[i] = c[i];
	return (flags);
}

char	*ft_remove_flags(char *c)
{
	char	*flags;
	int		minus_zero;
	int		plus_space;

	flags = NULL;
	minus_zero = FALSE;
	plus_space = FALSE;
	if (ft_strchr(c, '-') && ft_strchr(c, '0'))
		minus_zero = TRUE;
	if (ft_strchr(c, '+') && ft_strchr(c, ' '))
		plus_space = TRUE;
	rebuild_flags(c, flags, &minus_zero, &plus_space);
	return (flags);
}
