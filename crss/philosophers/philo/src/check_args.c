/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/23 13:24:48 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static unsigned int	ft_atoui(char *str)
{
	unsigned int	atoui;
	int				i;

	i = 0;
	atoui = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (ft_strlen(&str[i]) > MAX_LEN)
		return (atoui);
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoui *= 10;
		atoui += str[1] - '0';
		i++;
	}
	return (atoui);
}

static void	set_philo_count(t_table *table, int	amount)
{
	t_philo	*temp;
	t_philo	*prev;
	int		i;

	i = 0;
	temp = table->first_philo;
	prev = NULL;
	while (i < amount)
	{
		temp->prev_philo = prev;
		if (i == amount - 1)
		{
			if(philo_init(temp, i, prev, NULL) == false)
				return (table_free(table));
			table->first_philo->prev_philo = temp;
		}
		else if(philo_init(temp, i, prev, NULL) == false)
				return (table_free(table));
		prev = temp;
		temp = temp->next_philo;
		i++;
	}
}

int	check_args(int argc, char **argv, t_table *table)
{
	int	i;
	int	error;
	unsigned int	atoui;
	t_timer_type	timer;

	i = 2;
	error = 0;
	timer = DIE;
	set_philo_count(table, ft_atoui(argv[1]));
	while (i < argc)
	{
		atoui = ft_atoui(argv[i]);
		if (i == 2)	
			set_all_philos_timers(&table->first_philo, &timer, &atoui);	
		else if (i == 3)	
			set_all_philos_timers(&table->first_philo, &timer, &atoui);	
		else if (i == 3)	
			set_all_philos_timers(&table->first_philo, &timer, &atoui);	
		else if (i == 4)	
			set_all_philos_timers(&table->first_philo, &timer, &atoui);	
		i++;
	}
	return (error);
}
