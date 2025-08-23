/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:18:07 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/23 12:38:31 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.c"

static void	set_philo_timer(t_philo *philo, void *timer_type, void *limit)
{
	t_timer_type	timer;
	unsigned int	time_limit;

	time_limit = *(unsigned int *)limit;
	if (!timer_type)
	{
		philo->time_to_die = time_limit;
		philo->time_to_eat = time_limit;
		philo->time_to_sleep = time_limit;
		return ;
	}
	else
		timer = *(t_timer_type *)timer_type;
	if (timer == DIE)
		philo->time_to_die = time_limit;
	else if (timer == EAT)
		philo->time_to_eat = time_limit;
	else if (timer == SLEEP)
		philo->time_to_sleep = time_limit;
	else if (timer == MUST_EAT)
		philo->times_must_eat = time_limit;
}

void	set_all_philos_timers(t_philo **philos, void *timer_type, void *limit)
{
	unsigned int	time_limit;

	if (!limit)
		time_limit = 0;
	else
		time_limit = *(unsigned int *)limit;
	iter_over_philosophers(set_philo_timer, philos, timer_type, 0);
}
