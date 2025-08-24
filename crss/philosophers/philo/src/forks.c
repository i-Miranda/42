/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:18:43 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 19:48:52 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	pthread_mutex_lock(&philo->right_fork->mutex);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

t_fork	*fork_init(t_fork *fork)
{
	pthread_mutex_init(&fork->mutex, NULL);
	return (fork);
}

void	fork_free(t_fork *fork)
{
	pthread_mutex_destroy(&fork->mutex);
	free(fork);
	fork = NULL;
}
