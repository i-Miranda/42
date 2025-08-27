/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/27 12:52:43 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_for_table_started(t_table *table)
{
	while (true)
	{
		pthread_mutex_lock(&table->start_mutex);
		if (table->started)
			break ;
		pthread_mutex_unlock(&table->start_mutex);
		usleep(100);
	}
	pthread_mutex_unlock(&table->start_mutex);
}

static bool	check_for_philo_death(t_philo *philo, unsigned int *philos_done)
{
	unsigned long	philo_last_meal_ms;
	unsigned int	philo_meals_eaten;

	pthread_mutex_lock(&philo->mutex);
	philo_last_meal_ms = philo->last_meal_ms;
	philo_meals_eaten = philo->meals_eaten;
	if (timestamp_ms() - philo_last_meal_ms
		> (unsigned long)(philo->table->time_to_die))
	{
		if (!get_stop(philo->table))
		{
			print_timestamp_msg(philo, "has died");
			set_stop(philo->table, true);
			pthread_mutex_unlock(&philo->mutex);
		}
		return (true);
	}
	if (philo->table->times_must_eat > 0 && !philo->done
		&& philo_meals_eaten >= (unsigned long)philo->table->times_must_eat)
	{
		(*philos_done)++;
		philo->done = true;
	}
	pthread_mutex_unlock(&philo->mutex);
	return (false);
}

static void	check_for_table_done(t_table *table)
{
	t_philo			*philo;
	unsigned int	philos_done;

	philos_done = 0;
	while (!get_stop(table))
	{
		philo = table->philos;
		while (philo && !get_stop(table))
		{
			if (check_for_philo_death(philo, &philos_done))
				break ;
			if (!get_stop(table)
				&& table->times_must_eat > 0
				&& philos_done == (unsigned int)table->philo_count)
			{
				set_stop(table, true);
				break ;
			}
			philo = philo->next_philo;
		}
		usleep(1000);
	}
}

void	*table_update(void *table_param)
{
	t_table			*table;

	table = (t_table *)table_param;
	check_for_table_started(table);
	check_for_table_done(table);
	return (NULL);
}
