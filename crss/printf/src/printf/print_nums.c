/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 18:18:40 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*ft_base_16(int hex, int is_big, char *mod)
{
	int		i;

	i = 0;
	if (hex > 15)
	{
		mod[0] = hex / 16;
		mod[1] = hex % 16;
	}
	else
	{
		mod[0] = hex % 16;
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
		if (hex > 15 || (hex <= 15 && i == 0))
			mod[i] += '0';
		i++;
	}
	return (mod);
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

size_t	ft_print_hex(int hex, int is_big, char *flags)
{
	char	*output;
	int		j;
	size_t	len;

	len = 0;
	if (flags && ft_strchr(flags, '#'))
		len++;
	output = ft_calloc((len + 1) , sizeof(char));
	j = 0;
	if (flags && ft_strchr(flags, '#'))
	{
		output[j++] = '0';
		if (is_big == FALSE)
			output[j++] = 'x';
		else
			output[j++] = 'X';
	}
	ft_base_16(hex, is_big, &output[j]);
	j += 2;
	output[j] = '\0';
	len = ft_print_string(output);	
	free(output);
	return (len);
}

size_t	ft_print_uint(int u_int)
{
	char	*output;
	size_t	chars_printed;
	unsigned int overflow;
	int		i;

	overflow = 0;
	overflow += (unsigned int)u_int;
	i = 0;
	if (overflow == 0)
		i++;
	while (overflow)
	{
		overflow /= 10;
		i++;
	}
	overflow = 0;
	overflow += (unsigned int)u_int;
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
