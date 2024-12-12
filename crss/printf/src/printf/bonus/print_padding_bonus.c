/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:30:14 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 11:06:46 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

size_t	ft_print_padding(char *output, char *flags)
{
	size_t	chars_printed;
	char	*atoi_flags;
	int		padding;

	padding = 0;
	chars_printed = 0;
	if (flags && output[0] != '-')
	{
		if (ft_strchr(flags, '+'))
			chars_printed += ft_print_char('+');
		if (ft_strchr(flags, ' '))
			chars_printed += ft_print_char(' ');
	}
	if (flags && ft_strchr(flags, '0'))
	{
		padding = ft_atoi(ft_strchr(flags, '0')) - (int)ft_strlen(output);
		while (padding-- > 0)
			chars_printed += ft_print_char('0');
	}
	chars_printed += ft_print_string(output, NULL);
	if (flags && ft_strchr(flags, '-'))
	{
		atoi_flags = ft_strchr(flags, '-');	
		padding = ft_atoi(++atoi_flags) - (int)ft_strlen(output);
		while (padding-- > 0)
			chars_printed += ft_print_char(' ');
	}
	return (chars_printed);
}
