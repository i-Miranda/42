/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/16 01:06:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*ft_base_16(int hex, int is_big)
{
	char	*mod;
	int		i;

	mod = ft_calloc((2 + 1), sizeof(char));
	i = 0;
	if (hex == 0)
		mod[i] = '0';
	while (hex != 0)
	{
		mod[i] = hex % 16;
		hex = hex / 16;
		if (hex == 0 && i == 0)
			mod[i + 1] = 0;
		i++;
	}
	while (i >= 0)
	{
		if (mod[i] >= 10 && mod[i] <= 15)
		{
			if (is_big == 0)
				mod[i] += 39;
			else
				mod[i] += 39;
		}
		i--;
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

size_t	ft_print_hex(int hex, int is_big)
{
	char	*itoa;
	char	*output;
	int		i;
	int		j;
	size_t	len;

	itoa = ft_itoa(hex);
	len = ft_strlen(itoa);
	output = ft_calloc(((len * 2) + 1) , sizeof(char));
	i = 0;
	j = 0;
	while (itoa[i])
	{
		output[j] = *ft_base_16(itoa[i] - '0', is_big);
		i++;
		j += 2;
	}
	free(itoa);
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
