/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_over_philosophers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:04:15 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/23 13:25:33 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	iter_func_over_philosophers(void (*func)(t_philo *, void *, void *),
		t_philo **philo, void *param_first, void *param_second)
{
	t_philo	*current;

	current = *philo;
	while (current)
	{
		func(current, param_first, param_second);
		current = current->next_philo;
	}
}
