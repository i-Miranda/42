/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/25 11:57:21 by ivmirand         ###   ########.fr       */
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
	table->philo_count = ft_atoui(argv[1]);
	table->time_to_die = ft_atoui(argv[2]);
	table->time_to_eat = ft_atoui(argv[3]);
	table->time_to_sleep = ft_atoui(argv[4]);
	if (argc == 6)
		table->times_must_eat = ft_atoui(argv[5]);
	else
		table->times_must_eat = 0;
	table->stop = false;
	error = table_init(table);
	return (error);
}
