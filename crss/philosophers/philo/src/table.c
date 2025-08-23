/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivan              #+#    #+#             */
/*   Updated: 2025/08/23 13:26:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	table_init(t_table *table)
{
	philo_init(table->first_philo, 1, NULL, table->first_fork);
	table->philo_count = 1;
	fork_init(table->first_fork, table->first_philo);
	table->fork_count = 1;
}

void	table_free(t_table *table)
{
	t_philo	*current_philo;
	t_philo	*temp_philo;
	t_fork	*current_fork;
	t_fork	*temp_fork;

	current_philo = table->first_philo;
	while (current_philo != NULL)
	{
		temp_philo = current_philo->next_philo;
		philo_free(current_philo);
		current_philo = temp_philo;
	}
	current_fork = table->first_fork;
	while (current_fork != NULL)
	{
		temp_fork = current_fork->next_fork;
		fork_free(current_fork);
		current_fork = temp_fork;
	}
	table->philo_count = 0;
	table->fork_count = 0;
	table->first_philo = NULL;
	table->first_fork = NULL;
}

int	table_bon_apetit(t_table *table)
{
	int	error;

	return (error);
}
