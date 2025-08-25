/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:18:07 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/25 12:37:54 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	get_stop(t_table *table)
{
	bool	stop;

	pthread_mutex_lock(&table->stop_mutex);
	stop = table->stop;
	pthread_mutex_unlock(&table->stop_mutex);
	return (stop);
}

void	set_stop(t_table *table, bool stop)
{
	pthread_mutex_lock(&table->stop_mutex);
	table->stop = stop;
	pthread_mutex_unlock(&table->stop_mutex);
}

void	usleep_until_stop(t_table *table, unsigned long ms)
{
	unsigned long	end;
	unsigned long	now;
	unsigned long	time_left;

	end = timestamp_ms() + ms;
	while (!get_stop(table))
	{
		now = timestamp_ms();
		if (now >= end)
			break ;
		time_left = end - now;
		if (time_left > 2)
			usleep(1000);
		else
			usleep(100);
	}
}

unsigned long	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
}
