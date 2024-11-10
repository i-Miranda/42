/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:00:07 by ivmirand          #+#    #+#             */
/*   Updated: 2024/11/10 14:19:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	*ft_base_16(int hex)
{
	int		mod[2];

	if (hex == 0)
		output[i] = '0';
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
			mod[i] += 39;
		hexval = mod[i] + '0';
		i--;
	}
	return (mod);
}

int	ft_print_int(int nbr)
{
	char	*output;

	output = ft_itoa(nbr, 1);
	return (ft_print_string(output));
}

int	ft_print_hex(int hex, int is_big)
{
	char	*output;

	return (ft_print_string(output));
}
