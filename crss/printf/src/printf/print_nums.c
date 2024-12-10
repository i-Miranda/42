/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/12/10 21:19:23 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_base_16(unsigned char byte, int is_big, char *mod)
{
	int		i;

	i = 0;
	if (byte > 15)
	{
		mod[0] = byte / 16;
		mod[1] = byte % 16;
	}
	else
	{
		mod[0] = byte % 16;
		mod[1] = '\0';
	}
	while (i <= 1)
	{
		if (mod[i] >= 10 && mod[i] <= 15)
		{
			if (is_big == TRUE)
				mod[i] += 7;
			else
				mod[i] += 39;
		}
		mod[i] += '0';
		i++;
	}
}

size_t	ft_print_hexbyte(unsigned char byte, int is_big)
{
	char	*output;
	int		j;
	size_t	len;

	len = 2;
	output = ft_calloc(len + 1, sizeof(char));
	j = 0;
	ft_base_16(byte, is_big, &output[j]);
	if (byte > 15)
		j++;
	j++;
	output[j] = '\0';
	len = ft_print_string(output, NULL);
	free(output);
	return (len);
}

size_t	ft_print_hex(void *hex, int is_big, char *flags, int i)
{
	unsigned char	*uchar_hex;
	size_t			result;

	if (hex == 0)
		return (ft_print_string("0", NULL));
	uchar_hex = (unsigned char *)&hex;
	result = 0;
	if (flags && ft_strchr(flags, '#'))
	{
		if (is_big == FALSE)
			result += ft_print_string("0x", NULL);
		else
			result += ft_print_string("0X", NULL);
	}
	while (uchar_hex[i] == '\0' && i > 0)
		i--;
	if (uchar_hex[i] <= 15)
		result += ft_print_hexbyte(uchar_hex[i--], is_big);
	while (i >= 0)
	{
		if (uchar_hex[i] <= 15)
			result += ft_print_string("0", NULL);
		result += ft_print_hexbyte(uchar_hex[i], is_big);
		i--;
	}
	return (result);
}

size_t	ft_print_int(int nbr, char *flags)
{
	char	*output;
	char	*atoi_flags;
	int		padding;
	size_t	chars_printed;

	chars_printed = 0;
	padding = 0;
	output = ft_itoa(nbr);
	if (flags && nbr >= 0)
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
	free(output);
	return (chars_printed);
}

size_t	ft_print_uint(unsigned int u_int)
{
	char			*output;
	size_t			chars_printed;
	unsigned int	overflow;
	int				i;

	overflow = 0;
	overflow += u_int;
	i = 0;
	if (overflow == 0)
		i++;
	while (overflow != 0)
	{
		overflow /= 10;
		i++;
	}
	overflow = 0;
	overflow += u_int;
	output = ft_calloc(i + 1, sizeof(char));
	if (output == NULL)
		return (-1);
	if (overflow == 0)
		output[0] = '0';
	while (i-- && overflow > 0)
	{
		output[i] = (overflow % 10) + '0';
		overflow /= 10;
	}
	chars_printed = ft_print_string(output, NULL);
	free(output);
	return (chars_printed);
}
