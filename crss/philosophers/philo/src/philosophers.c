/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 02:46:28 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_init(t_philo *philo, int index, t_table *table)
{
	philo->index = index;
	philo->left_fork = &table->forks[index];
	philo->right_fork = &table->forks[(index + 1) % table->philo_count];
	pthread_mutex_init(&philo->mutex, NULL);
	philo->prev_philo = &table->philos[(index + 1) % table->philo_count];
	philo->next_philo = &table->philos[(index + table->philo_count - 1) 
		% table->philo_count];
	return (true);
}

//true means alive false means dead
bool	philo_update(t_philo *philo, t_table *table, unsigned int timer)
{
	if (timer > table->time_to_die)
		pthread_detach(philo->thread);
	else
	{
		if (philo->state == THINKING)
		{
			if (pthread_mutex_lock(&philo->left_fork->mutex)
				&& pthread_mutex_lock(&philo->right_fork->mutex))
				philo->state = EATING;
		}
		if (philo->state == EATING && timer > table->time_to_eat)
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			pthread_mutex_unlock(&philo->right_fork->mutex);
			philo->state = SLEEPING;
		}
		if (philo->state == SLEEPING && timer > table->time_to_sleep)
			philo->state = THINKING;
	}
	return (true);
}

void	*philo_free(t_philo *philo)
{
	free(philo);
	philo = NULL;
	return (philo);
}

t_fork	*fork_init(t_fork *fork)
{
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	*fork_free(t_fork *fork)
{
	pthread_mutex_destroy(&fork->mutex);
	free(fork);
	fork = NULL;
	return (fork);
}
