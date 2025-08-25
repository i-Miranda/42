/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:18:43 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/25 12:35:36 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_fork_order(t_philo *philo, t_fork **first, t_fork **second)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
}

static bool	check_for_missing_fork(t_philo *philo)
{
	if (philo->left_fork == NULL)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_philo_state(philo, "has taken a fork");
		return (true);
	}
	return (false);
}

bool	take_forks(t_philo *philo)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	if (check_for_missing_fork(philo))
		return (true);
	set_fork_order(philo, &first_fork, &second_fork);
	pthread_mutex_lock(&first_fork->mutex);
	if (get_stop(philo->table))
	{
		pthread_mutex_unlock(&first_fork->mutex);
		return (false);
	}
	print_philo_state(philo, "has taken a fork");
	pthread_mutex_lock(&second_fork->mutex);
	if (get_stop(philo->table))
	{
		pthread_mutex_unlock(&second_fork->mutex);
		pthread_mutex_unlock(&first_fork->mutex);
		return (false);
	}
	print_philo_state(philo, "has taken a fork");
	return (true);
}

void	drop_forks(t_philo *philo)
{
	t_fork	*first_fork;
	t_fork	*second_fork;

	if (philo->left_fork == NULL)
	{
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
	}
	set_fork_order(philo, &first_fork, &second_fork);
	pthread_mutex_unlock(&first_fork->mutex);
	pthread_mutex_unlock(&second_fork->mutex);
}

void	fork_free(t_fork *fork)
{
	pthread_mutex_destroy(&fork->mutex);
	free(fork);
	fork = NULL;
}
