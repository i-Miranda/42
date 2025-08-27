/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_apetit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/27 12:23:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	create_all_philos_threads(t_table *table)
{
	t_philo	*philo;

	philo = table->philos;
	while (philo)
	{
		pthread_create(&philo->thread, NULL, philo_update, philo);
		philo = philo->next_philo;
		if (philo == table->philos)
			break ;
	}
}

static void	check_all_philos_for_ready(t_table *table)
{
	unsigned int	all_ready;

	while (true)
	{
		pthread_mutex_lock(&table->start_mutex);
		all_ready = table->ready;
		pthread_mutex_unlock(&table->start_mutex);
		if (all_ready == (unsigned int)table->philo_count)
			break ;
		usleep(100);
	}
}

static void	set_all_philos_last_meal_ms(t_table *table)
{
	t_philo	*philo;

	pthread_mutex_lock(&table->start_mutex);
	table->start_time_ms = timestamp_ms();
	philo = table->philos;
	while (philo)
	{
		pthread_mutex_lock(&philo->mutex);
		philo->last_meal_ms = table->start_time_ms;
		pthread_mutex_unlock(&philo->mutex);
		philo = philo->next_philo;
		if (philo == table->philos)
			break ;
	}
	table->started = 1;
	pthread_mutex_unlock(&table->start_mutex);
}

static void	pthread_join_all_threads(t_table *table)
{
	t_philo	*philo;

	pthread_join(table->thread, NULL);
	philo = table->philos;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next_philo;
		if (philo == table->philos)
			break ;
	}
}

t_error	table_bon_apetit(t_table *table)
{
	t_error			error;

	error = ENONE;
	create_all_philos_threads(table);
	check_all_philos_for_ready(table);
	set_all_philos_last_meal_ms(table);
	pthread_create(&table->thread, NULL, table_update, table);
	pthread_join_all_threads(table);
	return (error);
}
