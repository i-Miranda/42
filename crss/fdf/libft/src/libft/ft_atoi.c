/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:50:35 by ivmirand          #+#    #+#             */
/*   Updated: 2025/03/18 15:39:53 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	result;
	long	neg;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f'))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * neg);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	neg;

	i = 0;
	result = 0;
	neg = 1;
	while ((str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\f'))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * neg);
}
