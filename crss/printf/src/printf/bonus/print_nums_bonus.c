/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 13:07:12 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

size_t	ft_print_hex_bonus(void *hex, int is_big, int i, char *flags)
{
	size_t			chars_printed;

	chars_printed = 0;
	if (flags && ft_strchr(flags, '#'))
	{
		if (is_big == FALSE)
			chars_printed += ft_print_string_bonus("0x", NULL);
		else
			chars_printed += ft_print_string_bonus("0X", NULL);
	}
	chars_printed += ft_print_hex(hex, is_big, i);
	return (chars_printed);
}

size_t	ft_print_int_bonus(int nbr, char *flags)
{
	char	*output;
	size_t	chars_printed;

	output = ft_itoa(nbr);
	chars_printed = ft_print_padding(output, flags);
	free(output);
	return (chars_printed);
}

size_t	ft_print_uint_bonus(unsigned int u_int, char *flags)
{
	char			*output;
	unsigned int	overflow;
	size_t			chars_printed;
	int				i;

	overflow = u_int;
	i = 0;
	if (overflow == 0)
		i++;
	while (overflow != 0)
	{
		overflow /= 10;
		i++;
	}
	output = ft_calloc(i + 1, sizeof(char));
	if (u_int == 0)
		output[0] = '0';
	while (i-- && u_int > 0)
	{
		output[i] = (u_int % 10) + '0';
		u_int /= 10;
	}
	chars_printed = ft_print_string_bonus(output, flags);
	free(output);
	return (chars_printed);
}
