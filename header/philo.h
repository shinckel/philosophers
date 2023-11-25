/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:36 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/24 15:02:54 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
// create threads
# include <pthread.h>
# include <limits.h>

// max number of philosophers
# define MAX_PHILO 200

// error messages
# define WRONG_ARGS "\e[1;41m Wrong args! max 200 philos, only '+' nbr \e[0m"

// lock threads execution until block of code is finished
typedef struct s_mutex
{
	pthread_mutex_t dead_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t think_lock;

} t_mutex;

typedef struct s_data
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}				t_data;

// Initializing the program structure

// Create threads and routine
// void    *routine(void *add);
// void    *routine2(void *add);

// Routine actions

// Free memory and destroy mutexes

#endif