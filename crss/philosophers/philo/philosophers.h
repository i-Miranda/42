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
	pthread_mutex_t	lock;
	struct s_philo	*holder;
	bool			is_held;		
}	t_fork;

typedef struct s_philo
{
	t_fork			*prev_fork;
	t_fork			*next_fork;
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
bool	philo_init(t_philo *philo, int index, t_philo *prev, t_philo *next, t_fork *p_fork, t_fork *n_fork);
bool	philo_update(t_philo *philo, int timer);
void	*philo_free(t_philo *philo);
void	*fork_init(t_fork *fork, t_philo *holder);
void	*fork_free(t_fork *fork);

//table functions
void	table_init();
void	table_free(t_table *table);
void	bon_apetit(t_table *table);

//check_args functions
int		check_args(int argc, char **argv, t_table *table);
#endif
