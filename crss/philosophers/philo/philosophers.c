/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/05/03 20:02:01 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	philo_init(t_philo *philo, int index, t_philo *prev, t_philo *next)
{
	philo = malloc(1 * sizeof(t_philosopher));
	if (philo == NULL)
		return (false);
	philo->state = is_thinking;
	philo->is_alive = true;
	philo->time_to_think = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->time_to_die = 0;
	philo->index = index;
	philo->prev_philo = prev;
	philo->next_philo = next;
	return (true);
}

bool	philo_update(t_philo *philo, int timer)
{
	if (!philo->is_alive || timer > philo->time_to_die)
		philo->is_alive == false;
	else
	{
		if (philo->state == is_thinking && timer > time_to_think)
			philo->state = is_hungry;
		if (philo->state == is_hungry && philo->target_fork->is_held == false)
		{
			philo->target_fork->is_held = true;
			philo->target_fork->holder = philo;
			philo->state = is_eating;
		}
		if (philo->state == is_eating && timer > time_to_eat)
		{
			philo->target_fork->is_held = false;
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
