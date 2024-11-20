/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/20 20:15:06 by ivmirand         ###   ########.fr       */
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
	len = ft_print_string(output);
	free(output);
	return (len);
}

size_t	ft_print_hex(void *hex, int is_big, char *flags)
{
	unsigned char		*uchar_hex;
	int		i;
	size_t	result;

	i = 7;
//	if (sizeof(hex) == 8)
//		write(1,"!",1);
	if (hex == 0)
		return (ft_print_string("0"));
	uchar_hex = (unsigned char *)&hex;
	result = 0;
	if (flags && ft_strchr(flags, '#'))
	{
		if (is_big == FALSE)
			result += ft_print_string("0x");
		else
			result += ft_print_string("0X");
	}
	while (uchar_hex[i] == '\0')
		i--;
	if (uchar_hex[i] <= 15)
		result += ft_print_hexbyte(uchar_hex[i--], is_big);
	while (i >= 0)
	{
		if (uchar_hex[i] <= 15)
			result += ft_print_string("0");
		result += ft_print_hexbyte(uchar_hex[i--], is_big);
	}
	return (result);
}

size_t	ft_print_int(int nbr)
{
	char	*output;
	size_t	chars_printed;

	output = ft_itoa(nbr);
	chars_printed = ft_print_string(output);
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
	chars_printed = ft_print_string(output);
	free(output);
	return (chars_printed);
}
