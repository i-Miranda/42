/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/26 01:38:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_wait_to_start(t_philo *philo)
{
	bool	start;

	start = false;
	pthread_mutex_lock(&philo->table->start_mutex);
	philo->table->ready++;
	pthread_mutex_unlock(&philo->table->start_mutex);
	while (true)
	{
		pthread_mutex_lock(&philo->table->start_mutex);
		if (philo->table->started > 0)
			start = true;
		pthread_mutex_unlock(&philo->table->start_mutex);
		if (start)
			break ;
		usleep(100);
	}
}

static bool	philo_update_loop(t_philo *philo)
{
	if (!take_forks(philo))
		return (false);
	pthread_mutex_lock(&philo->mutex);
	philo->last_meal_ms = timestamp_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mutex);
	print_philo_state(philo, "is eating");
	usleep_until_stop(philo->table, philo->table->time_to_eat);
	drop_forks(philo);
	if (get_stop(philo->table))
		return (false);
	print_philo_state(philo, "is sleeping");
	usleep_until_stop(philo->table, philo->table->time_to_sleep);
	if (get_stop(philo->table))
		return (false);
	print_philo_state(philo, "is thinking");
	usleep(500);
	return (true);
}

void	*philo_update(void *philo_param)
{
	t_philo	*philo;	

	philo = (t_philo *)philo_param;
	philo_wait_to_start(philo);
	if (philo->table->philo_count == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		print_philo_state(philo, "has taken a fork");
		usleep_until_stop(philo->table, philo->table->time_to_die);
		pthread_mutex_unlock(&philo->right_fork);
		return (NULL);
	}
	if (philo->index % 2 == 0)
		usleep(2000);
	while (!get_stop(philo->table))
	{
		if (!philo_update_loop(philo))
			break ;
	}
	return (NULL);
}

void	philo_free(t_philo *philo)
{
	pthread_mutex_destroy(&philo->mutex);
	pthread_mutex_destroy(&philo->right_fork);
	free(philo);
	philo = NULL;
}

bool	philo_init(t_philo **philo, t_philo **prev_philo, int index,
			t_table *table)
{
	if (!*philo)
	{
		*philo = malloc(1 * sizeof(t_philo));
		if (!*philo)
			return (false);
	}
	(*philo)->index = index;
	(*philo)->prev_philo = *prev_philo;
	(*philo)->next_philo = NULL;
	if (prev_philo && *prev_philo)
	{
		(*philo)->prev_philo->next_philo = *philo;
		(*philo)->left_fork = &(*prev_philo)->right_fork;
	}
	pthread_mutex_init(&(*philo)->right_fork, NULL);
	pthread_mutex_init(&(*philo)->mutex, NULL);
	(*philo)->meals_eaten = 0;
	(*philo)->table = table;
	(*philo)->done = false;
	return (true);
}
