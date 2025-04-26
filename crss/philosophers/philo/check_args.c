/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:27:27 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 21:01:59 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int argc, char **argv)
{
	int				i;
	int				error;
	t_philosophers	philo;

	i = 1;
	error = 0;
	while (i < argc)
	{
		if (i == 1)
			error = set_philo_count(argv[i]);	
		else if (i == 2)	
			error = set_time_to_die(argv[i]);	
		i++;
	}
	return (error);
}
