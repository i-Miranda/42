/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:28:17 by ivmirand          #+#    #+#             */
/*   Updated: 2025/05/03 20:03:32 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h> //write, usleep
#include <stdlib.h> //malloc, free
#include <stdio.h> //printf
#include <string.h> //memset
#include <sys/time.h> //gettimeofday
#include <pthread.h> //pthread_detach, pthread_join, pthread_mutex_init,
					 //pthread_mutex_destroy, pthread_mutex_lock,
					 //pthread_mutex_unlock
#include <stdbool.h>

typedef enum e_philo_state 
{
	is_thinking,
	is_hungry, 
	is_eating, 
	is_sleeping 
}	philo_state

typedef struct s_fork
{
	struct s_philo	*holder;
	bool			is_held;		
}	t_fork;

typedef struct s_philo
{
	t_fork			*target_fork;
	struct s_philo	*prev_philo;
	struct s_philo	*next_philo;
	philo_state		state;
	bool			is_alive;
	int				time_to_think;		
	int				time_to_Eat;		
	int				time_to_sleep;		
	int				time_to_die;		
	int				index;
}	t_philo;

typedef struct s_table
{
	t_philo	*first_philo;
	t_fork	*first_fork;
	int		philo_count;
	int		fork_count;
}	t_table;

//philosophers functions
t_philo	*philo_init(int index, int ttd, int tte, int tts);
bool	philo_update(t_philo *philo, int timer);
void	*philo_free(t_philo *philo);

//table functions
void	table_free(t_table *table);
bool	fork_init(t_fork *fork);

//check_args functions
int		check_args(int argc, char **argv, t_table *table);
#endif
