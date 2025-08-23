/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/23 13:52:45 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_init(t_philo *philo, int index, t_philo *prev, t_fork *fork)
{
	philo = malloc(1 * sizeof(t_philo));
	if (philo == NULL)
		return (false);
	philo->is_alive = true;
	philo->thread = pthread_create();
	philo->state = is_thinking;
	philo->index = index;
	philo->prev_philo = prev;
	philo->next_philo = NULL;
	philo->prev_fork = prev->fork;
	philo->fork = fork_init(fork, philo);
	return (true);
}

bool	philo_update(t_philo *philo, unsigned int timer)
{
	if (!philo->is_alive || timer > philo->time_to_die)
		philo->is_alive = false;
	else
	{
		if (philo->state == is_thinking && timer > philo->time_to_die)
			philo->is_alive = false;
		if (philo->state == is_thinking && philo->prev_fork->mutex)
		{
			philo->prev_fork->holder = philo;
			if (philo->state == is_thinking && philo->next_fork->mutex)
				philo->state = is_eating;
		}
		if (philo->state == is_eating && timer > time_to_eat)
		{
			philo->target_fork->holder = NULL;
			philo->state = is_sleeping;
		}
		if (philo->state == is_sleeping && time > time_to_sleep)
			philo->state = is_thinking;
	}
	return (philo->is_alive);
}

void	*philo_free(t_philo *philo)
{
	free(philo);
	philo = NULL;
	return (philo);
}

void	*fork_init(t_fork *fork, t_philo *holder)
{
	fork = malloc(1 * sizeof(t_fork);
	if (fork == NULL)
		return (NULL);
	pthread_mutex_init(&fork->mutex, NULL);
	fork->holder = holder;	
	return ((void *)fork);
}

void	*fork_free(t_fork *fork)
{
	pthread_mutex_destroy(&fork->lock);
	free(fork);
	fork = NULL;
	return (fork);
}
