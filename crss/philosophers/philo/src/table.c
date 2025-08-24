/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 02:55:09 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_error	table_init(t_table *table, int argc, char **argv)
{
	unsigned int	i;

	table->philo_count = ft_atoui(argv[1]);
	table->time_to_die = ft_atoui(argv[2]);
	table->time_to_eat = ft_atoui(argv[3]);
	table->time_to_sleep = ft_atoui(argv[4]);
	if (argc == 6)
		table->times_must_eat = ft_atoui(argv[5]);
	else
		table->times_must_eat = 0;
	table->philos = malloc(table->philo_count * sizeof(t_philo));
	table->forks = malloc(table->philo_count * sizeof(t_fork));
	if (!table->forks || !table->philos)
		return (ETABLE_INIT);
	pthread_mutex_init(&table->mutex, NULL);
	table->start_time_ms = timestamp_ms();
	i = 0;
	while (i < table->philo_count)
	{
		philo_init(&table->philos[i], i, table);	
		i++;
	}
	return (ENONE);
}

void	table_free(t_table *table)
{
	t_philo	*current_philo;
	t_philo	*temp_philo;
	int		i;

	current_philo = table->philos;
	while (current_philo != NULL)
	{
		temp_philo = current_philo->next_philo;
		philo_free(current_philo);
		current_philo = temp_philo;
	}
	i = 0;	
	while (&(table->forks)[i] != NULL)
	{
		fork_free(&(table->forks)[i]);
		i++;
	}
	table->philo_count = 0;
	table->philos = NULL;
	table->forks = NULL;
}

t_error	table_bon_apetit(t_table *table)
{
	t_error	error;
	
	error = ENONE;
	(void)table;
	return (error);
}
