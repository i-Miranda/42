/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/26 01:22:20 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	check_for_philo_death(t_philo *philo, unsigned int *philos_done)
{
	unsigned long	philo_last_meal_ms;
	unsigned int	philo_meals_eaten;

	pthread_mutex_lock(&philo->mutex);
	philo_last_meal_ms = philo->last_meal_ms;
	philo_meals_eaten = philo->meals_eaten;
	if (timestamp_ms() - philo_last_meal_ms > philo->table->time_to_die)
	{
		if (!get_stop(philo->table))
		{
			print_timestamp_msg(philo, "has died");
			set_stop(philo->table, true);
			pthread_mutex_unlock(&philo->mutex);
		}
		return (true);
	}
	if (philo->table->times_must_eat > 0
		&& philo_meals_eaten >= philo->table->times_must_eat && !philo->done)
	{
		(*philos_done)++;
		philo->done = true;
	}
	pthread_mutex_unlock(&philo->mutex);
	return (false);
}

t_error	table_init(t_table *table)
{
	t_philo			*head;
	t_philo			*current;
	t_philo			*prev;
	unsigned int	i;

	i = 0;
	table->philos = NULL;
	head = table->philos;
	prev = NULL;
	while (i < table->philo_count)
	{
		current = NULL;
		philo_init(&current, &prev, i, table);
		if (!head)
			head = current;
		prev = current;
		if (i == table->philo_count - 1)
			head->left_fork = &current->right_fork;
		i++;
	}
	table->philos = head;
	pthread_mutex_init(&table->mutex, NULL);
	pthread_mutex_init(&table->stop_mutex, NULL);
	pthread_mutex_init(&table->start_mutex, NULL);
	table->ready = 0;
	table->started = 0;
	return (ENONE);
}

void	*table_update(void *table_param)
{
	t_table			*table;
	t_philo			*philo;
	unsigned int	philos_done;
	int				started;

	table = (t_table *)table_param;
	while (true)
	{
		pthread_mutex_lock(&table->start_mutex);
		started = table->started;
		pthread_mutex_unlock(&table->start_mutex);
		if (started)
			break;
		usleep(100);
	}
	philos_done = 0;
	while (!get_stop(table))
	{
		philo = table->philos;
		while (philo && !get_stop(table))
			if (check_for_philo_death(philo, &philos_done))
				break ;
		philo = philo->next_philo;
		if (!get_stop(table)
			&& table->times_must_eat > 0 && philos_done == table->philo_count)
		{
			set_stop(table, true);
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void	table_free(t_table *table)
{
	t_philo			*current_philo;
	t_philo			*temp_philo;

	current_philo = table->philos;
	while (current_philo != NULL)
	{
		temp_philo = current_philo->next_philo;
		philo_free(current_philo);
		current_philo = temp_philo;
		if (current_philo == table->philos)
			break ;
	}
	table->philo_count = 0;
	table->philos = NULL;
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_destroy(&table->stop_mutex);
	pthread_mutex_destroy(&table->start_mutex);
}

t_error	table_bon_apetit(t_table *table)
{
	t_philo			*philo;
	t_error			error;
	unsigned int	all_ready;

	error = ENONE;
	philo = table->philos;
	while (philo)
	{
		pthread_create(&philo->thread, NULL, philo_update, philo);
		philo = philo->next_philo;
		if (philo == table->philos)
			break ;
	}
	while (true)
	{
		pthread_mutex_lock(&table->start_mutex);
		all_ready = table->ready;
		pthread_mutex_unlock(&table->start_mutex);
		if (all_ready == table->philo_count)
			break ;
		usleep(100);
	}
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
	pthread_create(&table->thread, NULL, table_update, table);
	pthread_join(table->thread, NULL);
	philo = table->philos;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next_philo;
	}
	return (error);
}
