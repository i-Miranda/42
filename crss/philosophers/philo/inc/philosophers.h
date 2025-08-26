/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:28:17 by ivmirand          #+#    #+#             */
/*   Updated: 2025/08/26 02:19:13 by ivmirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define _DEFAULT_SOURCE
# define PHILOSOPHERS_H

# include <unistd.h>	//write, usleep
# include <stdlib.h>	//malloc, free
# include <stdio.h>		//printf
# include <string.h>	//memset
# include <sys/time.h>	//gettimeofday
# include <pthread.h>	//pthread_detach, pthread_join, pthread_mutex_init,
						//pthread_mutex_destroy, pthread_mutex_lock,
						//pthread_mutex_unlock
# include <stdbool.h>
# include <limits.h>

# define MAX_LEN 10

/*-------ENUMS---------*/
typedef enum e_error
{
	ENONE = 0,
	EARGC = 1,
	ETABLE_INIT = 2,
}	t_error;

/*-------STRUCTS-------*/
typedef struct s_philo
{
	struct s_table	*table;
	pthread_mutex_t	*left_fork;
	struct s_philo	*prev_philo;
	struct s_philo	*next_philo;
	pthread_t		thread;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	mutex;
	unsigned long	last_meal_ms;
	unsigned int	meals_eaten;
	unsigned int	index;
	bool			done;
}	t_philo;

typedef struct s_table
{
	pthread_t		thread;
	unsigned long	start_time_ms;
	bool			stop;
	unsigned int	philo_count;
	unsigned int	time_to_eat;		
	unsigned int	time_to_sleep;		
	unsigned int	time_to_die;		
	unsigned int	times_must_eat;
	t_philo			*philos;
	pthread_mutex_t	mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	start_mutex;
	unsigned int	ready;
	unsigned int	started;
}	t_table;

//philosophers functions
bool			philo_init(t_philo **philo, t_philo **prev_philo, int index,
					t_table *table);
void			*philo_update(void *table_param);
void			philo_free(t_philo *philo);

//forks functions
bool			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);

//table functions
t_error			table_init(int argc, char **argv, t_table *table);
void			table_free(t_table *table);

//table_update functions
void			*table_update(void *table_param);

//bon_apetit functions
t_error			table_bon_apetit(t_table *table);

//check_args functions
unsigned int	ft_atoui(char *str);
int				check_args(int argc, char **argv, t_table *table);

//timers functions
bool			get_stop(t_table *table);
void			set_stop(t_table *table, bool stop);
void			usleep_until_stop(t_table *table, unsigned long ms);
unsigned long	timestamp_ms(void);

//print functions
ssize_t			print_string_fd(const char *str, int fd);
ssize_t			print_uint_fd(unsigned long n, int fd);
ssize_t			print_philo_state(t_philo *philo, char *msg);
void			print_timestamp_msg(t_philo *philo, const char *msg);
#endif
