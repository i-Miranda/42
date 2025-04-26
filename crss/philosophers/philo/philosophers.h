/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivmirand <ivmirand@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:28:17 by ivmirand          #+#    #+#             */
/*   Updated: 2025/04/24 21:07:20 by ivmirand         ###   ########.fr       */
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

typedef struct s_philosopher
{
	philo_state state;
	bool		isAlive;
	int			timeToDie;		
	int			timeToEat;		
	int			timeToSleep;		
	int			index;
}	t_philosopher;
#endif
