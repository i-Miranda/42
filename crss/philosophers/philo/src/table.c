/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/27 12:28:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_all_philos(t_table *table)
{
	t_philo			*head;
	t_philo			*current;
	t_philo			*prev;
	unsigned int	i;

	i = 0;
	table->philos = NULL;
	head = table->philos;
	prev = NULL;
	while (i < (unsigned int)table->philo_count)
	{
		current = NULL;
		philo_init(&current, &prev, i, table);
		if (!head)
			head = current;
		prev = current;
		if (i == (unsigned int)(table->philo_count - 1))
			head->left_fork = &current->right_fork;
		i++;
	}
	table->philos = head;
}

t_error	table_init(t_table *table)
{
	table->stop = false;
	init_all_philos(table);
	pthread_mutex_init(&table->mutex, NULL);
	pthread_mutex_init(&table->stop_mutex, NULL);
	pthread_mutex_init(&table->start_mutex, NULL);
	table->ready = 0;
	table->started = 0;
	return (ENONE);
}

void	table_free(t_table *table)
{
	t_philo			*current_philo;
	t_philo			*temp_philo;

	current_philo = table->philos;
	while (current_philo != NULL)
	{
		temp_philo = current_philo->next_philo;
		philo_free(current_philo);
		current_philo = temp_philo;
		if (current_philo == table->philos)
			break ;
	}
	table->philo_count = 0;
	table->philos = NULL;
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_destroy(&table->stop_mutex);
	pthread_mutex_destroy(&table->start_mutex);
}
