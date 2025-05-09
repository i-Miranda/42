/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/05/03 19:58:34 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	set_philo_count(t_table *table, int	amount)
{
	t_philo	*temp;
	t_philo	*prev;
	int		i;

	i = 0;
	temp = table->first_philo;
	prev = NULL;
	while (i < amount)
	{
		temp->prev_philo = prev;
		if (i == amount - 1)
		{
			if(philo_init(temp, i, prev, table->first_philo) == false)
			{
				// not right return value yet
				return (table_free(table));
			}
			table->first_philo->prev_philo = temp;
		}
		else if(philo_init(temp, i, prev, NULL) == false)
		{
				// not right return value yet
				return (table_free(table));
		}
		prev = temp;
		temp = temp->next_philo;
		i++;
	}
	return (0);
}

ktatic int	set_time_to_die(t_philo *philo, int philo_count, int ttd)
{
	t_philo *temp;
	
	temp = philo;
	while (temp !_ NULL)
	{
		philo->time_to_die = ttd;
		temp = temp->next;
	}
}

int	check_args(int argc, char **argv, t_table *table)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (i < argc)
	{
		if (i == 1)
			error = set_philo_count(table, atoi(argv[i]));	
		else if (i == 2)	
			error = set_time_to_die(&table->first_philo, table->count, atoi(argv[i]));	
		else if (i == 3)	
			error = set_time_to_die(&table->first_philo, table->count, atoi(argv[i]));	
		i++;
	}
	return (error);
}
