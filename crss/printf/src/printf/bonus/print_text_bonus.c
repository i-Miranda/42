/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:35 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 18:55:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

static void	check_flags_for_period(int *charcount, char *flags)
{
	char	*atoi_flags;

	if (flags && ft_strchr(flags, '.'))
	{
		atoi_flags = ft_strchr(flags, '.');
		*charcount = ft_atoi(++atoi_flags);
	}
}

size_t	ft_print_char_bonus(int c, char *flags)
{
	check_flags_for_minus((char *)&c, flags);
	return (ft_print_char(c));
}

size_t	ft_print_string_bonus(char *str, char *flags)
{
	int		charcount;
	int		i;
	size_t	result;

	charcount = -1;
	i = 0;
	result = 0;
	check_flags_for_period(&charcount, flags);
	if (charcount > 0)
	{
		while (i < charcount)
		{
			if (str[i])
				result = ft_print_char(str[i]);
			else
				result += ft_print_char(' ');
			i++;
		}
	}
	else
		result = ft_print_string(str);
	return (result);
}
