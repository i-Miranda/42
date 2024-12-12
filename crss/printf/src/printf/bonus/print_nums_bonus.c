/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/12 11:42:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf_bonus.h"

static void	ft_base_16(unsigned char byte, int is_big, char *mod)
{
	int		i;

	i = 0;
	if (byte > 15)
	{
		mod[0] = (byte / 16) + '0';
		mod[1] = (byte % 16) + '0';
	}
	else
		mod[0] = (byte % 16) + '0';
	while (i <= 1)
	{
		if (mod[i] >= 10 + '0' && mod[i] <= 15 + '0')
		{
			if (is_big == TRUE)
				mod[i] += 7;
			else
				mod[i] += 39;
		}
		i++;
	}
}

size_t	ft_print_hexbyte(unsigned char byte, int is_big)
{
	char	*output;
	size_t	len;

	len = 2;
	output = ft_calloc(len + 1, sizeof(char));
	ft_base_16(byte, is_big, output);
	len = ft_print_string(output, NULL);
	free(output);
	return (len);
}

size_t	ft_print_hex(void *hex, int is_big, char *flags, int i)
{
	unsigned char	*uchar_hex;
	size_t			chars_printed;

	if (hex == 0)
		return (ft_print_string("0", NULL));
	uchar_hex = (unsigned char *)&hex;
	chars_printed = 0;
	if (flags && ft_strchr(flags, '#'))
	{
		if (is_big == FALSE)
			chars_printed += ft_print_string("0x", NULL);
		else
			chars_printed += ft_print_string("0X", NULL);
	}
	while (uchar_hex[i] == '\0' && i > 0)
		i--;
	if (uchar_hex[i] <= 15)
		chars_printed += ft_print_hexbyte(uchar_hex[i--], is_big);
	while (i >= 0)
	{
		if (uchar_hex[i] <= 15)
			chars_printed += ft_print_string("0", NULL);
		chars_printed += ft_print_hexbyte(uchar_hex[i--], is_big);
	}
	return (chars_printed);
}

size_t	ft_print_int(int nbr, char *flags)
{
	char	*output;
	size_t	chars_printed;

	output = ft_itoa(nbr);
	chars_printed = ft_print_padding(output, flags);
	free(output);
	return (chars_printed);
}

size_t	ft_print_uint(unsigned int u_int, char *flags)
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
	chars_printed = ft_print_string(output, flags);
	free(output);
	return (chars_printed);
}
