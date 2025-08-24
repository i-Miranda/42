/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 19:55:27 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static	ssize_t print_philo_state(t_philo *philo, t_table *table, char *msg)
{
	unsigned long	timestamp;
	ssize_t			print_len;

	print_len = 0;
	pthread_mutex_lock(&table->mutex);
	timestamp = timestamp_ms() - table->start_time_ms;
	print_len += print_uint_fd(timestamp, STDOUT_FILENO);
	print_len += print_string_fd(" ", STDOUT_FILENO);
	print_len += print_uint_fd((unsigned long)philo->index + 1, STDOUT_FILENO);
	print_len += print_string_fd(" ", STDOUT_FILENO);
	if (msg == NULL)
	{
		if (philo->state == EATING)
			print_len += print_string_fd("is eating\n", STDOUT_FILENO);
		else if (philo->state == SLEEPING)
			print_len += print_string_fd("is sleeping\n", STDOUT_FILENO);
		else if (philo->state == THINKING)
			print_len += print_string_fd("is thinking\n", STDOUT_FILENO);
		else
			print_len += print_string_fd("is dead\n", STDOUT_FILENO);
	}
	else
	{
		print_len += print_string_fd(msg, STDOUT_FILENO);
		print_len += print_string_fd("\n", STDOUT_FILENO);
	}
	pthread_mutex_unlock(&table->mutex);
	return (print_len);
}

void	*philo_update(void *table_param)
{
	t_table *table;	
	t_philo *philo;	

	table = (t_table *)table_param;
	philo = table->philos;
	if (table->philo_count == 1)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_philo_state(philo, table, NULL);
		usleep_until_stop(table, table->time_to_die);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return (NULL);
	}
	if (philo->index % 2 == 0)
		usleep(2000);
	while (!table->stop)
	{
		take_forks(philo);
		print_philo_state(philo, table, "has taken a fork");
		print_philo_state(philo, table, "has taken a fork");

		pthread_mutex_lock(&philo->mutex);
		philo->last_meal_ms = timestamp_ms();
		philo->state = EATING;
		pthread_mutex_unlock(&philo->mutex);
		print_philo_state(philo, table, NULL);
		usleep_until_stop(table, table->time_to_eat);

		drop_forks(philo);
		print_philo_state(philo, table, "has put down a fork");
		print_philo_state(philo, table, "has put down a fork");

		pthread_mutex_lock(&philo->mutex);
		philo->meals_eaten++;
		philo->state = SLEEPING;
		pthread_mutex_unlock(&philo->mutex);
		print_philo_state(philo, table, NULL);
		usleep_until_stop(table, table->time_to_sleep);

		pthread_mutex_lock(&philo->mutex);
		philo->state = THINKING;
		pthread_mutex_unlock(&philo->mutex);
		print_philo_state(philo, table, NULL);
	}
	return (NULL);
}

void	philo_free(t_philo *philo)
{
	free(philo);
	philo = NULL;
}

bool	philo_init(t_philo *philo, int index, t_table *table)
{
	philo->index = index;
	philo->left_fork = &table->forks[(index - 1) % table->philo_count];
	philo->right_fork = &table->forks[(index + 1) % table->philo_count];
	pthread_mutex_init(&philo->mutex, NULL);
	philo->prev_philo = &table->philos[(index - 1) % table->philo_count];
	philo->next_philo = &table->philos[(index + 1) % table->philo_count];
	philo->last_meal_ms = table->start_time_ms;
	philo->meals_eaten = 0;
	philo->state = THINKING;
	return (true);
}
