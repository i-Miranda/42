/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:28:17 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/23 13:52:25 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>		//write, usleep
#include <stdlib.h>		//malloc, free
#include <stdio.h>		//printf
#include <string.h>		//memset
#include <sys/time.h>	//gettimeofday
#include <pthread.h>	//pthread_detach, pthread_join, pthread_mutex_init,
						//pthread_mutex_destroy, pthread_mutex_lock,
						//pthread_mutex_unlock
#include <stdbool.h>

#define	MAX_LEN	10

typedef enum e_philo_state 
{
	is_thinking,
	is_eating, 
	is_sleeping 
}	t_philo_state;

typedef enum e_timer_type 
{
	DIE,
	EAT, 
	SLEEP, 
	MUST_EAT 
}	t_timer_type;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	struct s_philo	*holder;
}	t_fork;

typedef struct s_philo
{
	pthread			thread;
	t_fork			*prev_fork;
	t_fork			*fork;
	struct s_philo	*prev_philo;
	struct s_philo	*next_philo;
	t_philo_state		state;
	bool			is_alive;
	unsigned int	time_to_eat;		
	unsigned int	time_to_sleep;		
	unsigned int	time_to_die;		
	unsigned int	times_must_eat;
	unsigned int	index;
}	t_philo;

typedef struct s_table
{
	t_philo	*first_philo;
	t_philo	*last_philo;
	t_fork	*first_fork;
	t_fork	*last_fork;
	int		philo_count;
	int		fork_count;
}	t_table;

//philosophers functions
bool	philo_init(t_philo *philo, int index, t_philo *prev, t_fork *fork);
bool	philo_update(t_philo *philo, unsigned int timer);
void	*philo_free(t_philo *philo);
void	*fork_init(t_fork *fork, t_philo *holder);
void	*fork_free(t_fork *fork);

//table functions
void	table_init();
void	table_free(t_table *table);
int		table_bon_apetit(t_table *table);

//check_args functions
int		check_args(int argc, char **argv, t_table *table);

//timers functions
void	set_all_philos_timers(t_philo **philos, void *timer_type, void *limit);
#endif
