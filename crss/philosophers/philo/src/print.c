/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:06:13 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/25 12:50:56 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static ssize_t	print_msg(t_philo *philo, const char *msg)
{
	ssize_t	len;

	len = 0;
	if (msg == NULL)
	{
		if (philo->state == EATING)
			len += print_string_fd("is eating\n", STDOUT_FILENO);
		else if (philo->state == SLEEPING)
			len += print_string_fd("is sleeping\n", STDOUT_FILENO);
		else if (philo->state == THINKING)
			len += print_string_fd("is thinking\n", STDOUT_FILENO);
		else
			len += print_string_fd("is dead\n", STDOUT_FILENO);
	}
	else
	{
		len += print_string_fd(msg, STDOUT_FILENO);
		len += print_string_fd("\n", STDOUT_FILENO);
	}
	return (len);
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

ssize_t	print_philo_state(t_philo *philo, char *msg)
{
	unsigned long	timestamp;
	ssize_t			len;

	len = 0;
	pthread_mutex_lock(&philo->table->mutex);
	if (!get_stop(philo->table))
	{
		timestamp = timestamp_ms() - philo->table->start_time_ms;
		len += print_uint_fd(timestamp, STDOUT_FILENO);
		len += print_string_fd(" ", STDOUT_FILENO);
		len += print_uint_fd((unsigned long)(philo->index + 1), STDOUT_FILENO);
		len += print_string_fd(" ", STDOUT_FILENO);
		len += print_msg(philo, msg);
	}
	pthread_mutex_unlock(&philo->table->mutex);
	return (len);
}

void	print_timestamp_msg(t_philo *philo, const char *msg)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&philo->table->mutex);
	if (!get_stop(philo->table))
	{
		timestamp = timestamp_ms() - philo->table->start_time_ms;
		print_uint_fd(timestamp, STDOUT_FILENO);
		write(STDOUT_FILENO, " ", 1);
		print_uint_fd(philo->index + 1, STDOUT_FILENO);
		write(STDOUT_FILENO, " ", 1);
		print_msg(philo, msg);
	}
	pthread_mutex_unlock(&philo->table->mutex);
}
