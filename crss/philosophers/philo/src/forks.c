/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 14:18:43 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/25 23:43:12 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_fork_order(t_philo *philo, pthread_mutex_t **first,
		pthread_mutex_t **second)
{
	if (philo->left_fork < &philo->right_fork)
	{
		*first = philo->left_fork;
		*second = &philo->right_fork;
	}
	else
	{
		*first = &philo->right_fork;
		*second = philo->left_fork;
	}
}

bool	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	set_fork_order(philo, &first_fork, &second_fork);
	pthread_mutex_lock(first_fork);
	if (get_stop(philo->table))
	{
		pthread_mutex_unlock(first_fork);
		return (false);
	}
	print_philo_state(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	if (get_stop(philo->table))
	{
		pthread_mutex_unlock(second_fork);
		pthread_mutex_unlock(first_fork);
		return (false);
	}
	print_philo_state(philo, "has taken a fork");
	return (true);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->left_fork == NULL)
	{
		pthread_mutex_unlock(&philo->right_fork);
		return ;
	}
	set_fork_order(philo, &first_fork, &second_fork);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}
