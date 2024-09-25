/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:05:26 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/26 00:43:06 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intdigits(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;

	if (n == 0)
		return ("0");
	if (n == -2147483648)
		return ("-2147483648");
	array = malloc(ft_intdigits(n) * sizeof(char));
	if (array == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		array[i++] = '-';
	}
	while (n >= 0)
	{
		array[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (array);
}
