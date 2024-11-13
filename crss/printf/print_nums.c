/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/13 15:24:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char *ft_base_16(int hex, int is_big)
{
	char	*mod;
	int		i;

	mod = malloc((2 + 1) * sizeof(char));
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

	output = ft_itoa(nbr);
	return (ft_print_string(output));
}

size_t	ft_print_hex(int hex, int is_big)
{
	char	*itoa;
	char	*output;
	int		i;
	int		j;
	size_t	itoa_len;

	itoa = ft_itoa(hex);
	itoa_len = ft_strlen(itoa);	
	output = malloc(((itoa_len * 2) + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (itoa[i])
	{
		output[j] = *ft_base_16(itoa[i] - '0', is_big);		
		i++;
		j += 2;
	}
	free(itoa);
	return (ft_print_string(output));
}

size_t	ft_print_udec(unsigned int u_int)
{
	char			*output;
	unsigned float	value;
	
	return (ft_print_string(output));
}
