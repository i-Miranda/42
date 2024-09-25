/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:05:26 by ivmirand          #+#    #+#             */
/*   Updated: 2024/09/25 22:19:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intdigits(int n)
{
	int	i;

	i = 0;
	if (n > 0)
		i++;
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

	array = malloc(ft_intdigits(n) * sizeof(char));
	if (array == NULL)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
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
