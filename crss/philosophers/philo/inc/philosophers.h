/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:28:17 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/24 02:55:29 by ivmirand         ###   ########.fr       */
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

#define	MAX_LEN 10
#define	ARGC_ERROR 1

typedef enum e_error
{
	ENONE = 0,
	EARGC = 1,
	ETABLE_INIT = 2,
	
}	t_error;

typedef enum e_philo_state 
{
	THINKING,
	EATING, 
	SLEEPING,
	DEAD
}	t_philo_state;


typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	unsigned int	index;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	unsigned long	last_meal_ms;
	unsigned int	meals_eaten;
	struct s_philo	*prev_philo;
	struct s_philo	*next_philo;
	t_philo_state	state;
}	t_philo;

typedef struct s_table
{
	unsigned long	start_time_ms;
	unsigned int	philo_count;
	unsigned int	time_to_eat;		
	unsigned int	time_to_sleep;		
	unsigned int	time_to_die;		
	unsigned int	times_must_eat;
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	mutex;
}	t_table;

//philosophers functions
bool			philo_init(t_philo *philo, int index, t_table *table);
bool			philo_update(t_philo *philo, t_table *table, unsigned int timer);
void			*philo_free(t_philo *philo);
t_fork			*fork_init(t_fork *fork);
void			*fork_free(t_fork *fork);

//table functions
t_error			table_init(t_table *table, int argc, char **argv);
void			table_free(t_table *table);
t_error			table_bon_apetit(t_table *table);

//check_args functions
unsigned int	ft_atoui(char *str);
int				check_args(int argc, char **argv, t_table *table);

//timers functions
unsigned long	timestamp_ms(void);
unsigned long	print_timestamp_msg(t_table *table, int philo_id,
				const char *msg);
#endif
