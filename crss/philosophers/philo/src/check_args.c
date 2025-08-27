/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/27 12:38:20 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_atoi(char *str)
{
	long			atoi;
	int				i;
	int				neg;

	i = 0;
	neg = 1;
	atoi = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi *= 10;
		atoi += str[i] - '0';
		i++;
	}
	return ((long)atoi * neg);
}

//unsigned int	ft_atoui(char *str)
//{
//	unsigned long	atoui;
//	int				i;
//	size_t			len;
//
//	i = 0;
//	atoui = 0;
//	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
//		i++;
//	len = 0;
//	if (str[i] == '+' || str[i] == '-')
//		return (atoui);
//	while (str[i + len])
//		len++;
//	if (len > MAX_LEN)
//		return (atoui);
//	while (str[i] >= '0' && str[i] <= '9')
//	{
//		atoui *= 10;
//		atoui += str[i] - '0';
//		if (atoui > UINT_MAX)
//			return (0);
//		i++;
//	}
//	return ((unsigned int)atoui);
//}

int	check_args(int argc, char **argv, t_table *table)
{
	t_error	error;

	error = ENONE;
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->times_must_eat = ft_atoi(argv[5]);
	else
		table->times_must_eat = 0;
	if (table->philo_count < 0 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0
		|| table->times_must_eat < 0)
	{
		print_string_fd("Error: values must be greater or equal to 0\n",
			STDERR_FILENO);
		return (EARGV);
	}
	error = table_init(table);
	return (error);
}
