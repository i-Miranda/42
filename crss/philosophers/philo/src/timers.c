/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:18:07 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 18:36:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	usleep_until_stop(t_table *table, unsigned long ms)
{
	unsigned long end;
	unsigned long now;
	unsigned long time_left;

	end = timestamp_ms() + ms;
	while (!table->stop)
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

ssize_t	print_string_fd(const char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (write(fd, str, i));
}

ssize_t	print_uint_fd(unsigned long n, int fd)
{
	char	buf[21];
	int		i;
	
	i = 20;
	buf[i] = '\0';
	if (n == 0)
		write(fd, "0", 1);
	while (n > 0)
	{
		buf[--i] = '0' + (n % 10);
		n /= 10;
	}
	return (write(fd, buf + i, 20 - i));
}

unsigned long	timestamp_ms(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000UL + tv.tv_usec / 1000UL);
}

void	print_timestamp_msg(t_table *table, int philo_id,
	const char *msg)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&table->mutex);
	if (!table->stop)
	{
		timestamp = timestamp_ms() - table->start_time_ms;	
		print_uint_fd(timestamp, STDOUT_FILENO);
		write(STDOUT_FILENO, " ", 1);
		print_uint_fd(philo_id, STDOUT_FILENO);
		write(STDOUT_FILENO, " ", 1);
		print_string_fd(msg, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
	}
	pthread_mutex_unlock(&table->mutex);
}
