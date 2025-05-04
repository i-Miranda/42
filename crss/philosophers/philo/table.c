/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:59:57 by ivan              #+#    #+#             */
/*   Updated: 2025/05/04 13:47:08 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

bool	fork_init(t_fork *fork)
{
	fork = malloc(1 * sizeof(fork));
	if (fork == NULL)
		return (false);
	fork->holder = NULL;
	fork->is_held = false;
	return (true);
}
