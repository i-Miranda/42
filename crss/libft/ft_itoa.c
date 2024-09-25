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
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	if (nbr == 0)
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
	array = malloc(ft_longdigits(nbr) + 1 * sizeof(char));
	if (array == NULL)
		return (NULL);
	ft_bzero(array, ft_strlen(array));
	ft_putstr_fd(array, 1);
	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		array[i++] = '-';
	}
	i = ft_longdigits(nbr);
	while (nbr > 0)
	{
		array[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (array);
}
