/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:05:26 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/26 01:42:16 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_longdigits(long nbr)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;
	long	nbr;

	nbr = n;
	i = ft_longdigits(nbr);
	array = ft_calloc(i + 2, sizeof(char));
	if (array == NULL)
		return (NULL);
	if (nbr == 0)
		array[0] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		array[0] = '-';
	}
	while (nbr > 0)
	{
		array[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (array);
}
