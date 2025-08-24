/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 18:54:24 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned int	ft_atoui(char *str)
{
	unsigned long	atoui;
	int				i;
	size_t			len;

	i = 0;
	atoui = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	len = 0;
	if (str[i] == '+' || str[i] == '-')
		return (atoui);
	while (str[i + len])
		len++;
	if (len > MAX_LEN)
		return (atoui);
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoui *= 10;
		atoui += str[i] - '0';
		if (atoui > UINT_MAX)
			return (0);
		i++;
	}
	return ((unsigned int)atoui);
}

int	check_args(int argc, char **argv, t_table *table)
{
	t_error	error;

	error = ENONE;
	error = table_init(table, argc, argv);
	return (error);
}
