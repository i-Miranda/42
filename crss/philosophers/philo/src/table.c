/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 19:48:40 by ivmirand         ###   ########.fr       */
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
	table->stop = false;
	return (ENONE);
}

void	*table_update(void *table_param)
{
	t_table	*table;
	t_philo	*philo;
	unsigned long	philo_last_meal_ms;
	unsigned long	time_of_death;
	unsigned int	philo_meals_eaten;
	unsigned int	philos_done;

	table = (t_table *)table_param;
	while (!table->stop)
	{
		philo = table->philos;
		philos_done = 0;
		while (philo && !table->stop)
		{
			pthread_mutex_lock(&philo->mutex);
			philo_last_meal_ms = philo->last_meal_ms;
			philo_meals_eaten = philo->meals_eaten;
			pthread_mutex_unlock(&philo->mutex);
			if (timestamp_ms() - philo_last_meal_ms > table->time_to_die)
			{
				pthread_mutex_lock(&table->mutex);
				if (!table->stop)
				{
					time_of_death = timestamp_ms() - table->start_time_ms;
					print_uint_fd(time_of_death, STDOUT_FILENO);
					print_string_fd(" ", STDOUT_FILENO);
					print_uint_fd(philo->index + 1, STDOUT_FILENO);
					print_string_fd(" died\n", STDOUT_FILENO);
					table->stop = true;
				}
				pthread_mutex_unlock(&table->mutex);
				break ;
			}
			if (table->times_must_eat > 0
					&& philo_meals_eaten >= table->times_must_eat)
				philos_done++;
			philo = philo->next_philo;
		}
		if (!table->stop && 
				table->times_must_eat > 0 && philos_done > table->philo_count)
		{
			table->stop = true;
			break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void	table_free(t_table *table)
{
	t_philo			*current_philo;
	t_philo			*temp_philo;
	unsigned int	i;

	current_philo = table->philos;
	while (current_philo != NULL)
	{
		temp_philo = current_philo->next_philo;
		philo_free(current_philo);
		current_philo = temp_philo;
	}
	i = 0;	
	while (i < table->philo_count)
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
	t_philo 	*philo;
	t_error		error;
	
	error = ENONE;
	philo = table->philos;
	while (philo)
	{
		pthread_create(&philo->thread, NULL, philo_update, philo);
		philo = philo->next_philo;
	}
	pthread_create(&table->thread, NULL, table_update, table);
	pthread_join(table->thread, NULL);
	philo = table->philos;
	while (philo)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next_philo;
	}
	return (error);
}
