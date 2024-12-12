/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:30:14 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 18:57:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

static size_t	check_neg_output_flags(char *output, char *flags)
{
	size_t	chars_printed;

	chars_printed = 0;
	if (flags && output[0] != '-')
	{
		if (ft_strchr(flags, '+'))
			chars_printed += ft_print_char('+');
		if (ft_strchr(flags, ' '))
			chars_printed += ft_print_char(' ');
	}
	return (chars_printed);
}

static size_t	check_flags_for_zero(char *output, char *flags)
{
	size_t	chars_printed;
	char	*atoi_flags;
	int		padding;

	chars_printed = 0;
	if (flags && ft_strchr(flags, '0'))
	{
		atoi_flags = ft_strchr(flags, '0');
		padding = ft_atoi(++atoi_flags) - (int)ft_strlen(output);
		while (padding-- > 0)
			chars_printed += ft_print_char('0');
	}
	return (chars_printed);
}

size_t	check_flags_for_minus(char *output, char *flags)
{
	size_t	chars_printed;
	char	*atoi_flags;
	int		padding;

	chars_printed = 0;
	if (flags && ft_strchr(flags, '-'))
	{
		atoi_flags = ft_strchr(flags, '-');
		padding = ft_atoi(++atoi_flags) - (int)ft_strlen(output);
		while (padding-- > 0)
			chars_printed += ft_print_char(' ');
	}
	return (chars_printed);
}

size_t	ft_print_padding(char *output, char *flags)
{
	size_t	chars_printed;

	chars_printed = check_neg_output_flags(output, flags);
	chars_printed += check_flags_for_zero(output, flags);
	chars_printed += ft_print_string_bonus(output, NULL);
	chars_printed += check_flags_for_minus(output, flags);
	return (chars_printed);
}
