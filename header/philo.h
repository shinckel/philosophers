/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:36 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/03 00:01:08 by shinckel         ###   ########.fr       */
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
// utility functions regarding time
// # include <time.h>
# include <sys/time.h>

// max number of philosophers
# define MAX_PHILO 200

// error messages
# define WRONG_ARGS "\e[1;41m Wrong args! max 200 philos, only '+' nbr \e[0m"
# define CREATION_ERROR "\e[1;41m Error during threads creation \e[0m"
# define TIME_ERROR "\e[1;41m Error gettimeofday() \e[0m"
// action messages
# define THINK "is thinking..."
# define DREAM "is dreaming..."
# define EAT "is eating..."
# define FORK_L "has taken left fork..."
# define FORK_R "has taken right fork..."
# define DEATH "is dead..."

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				n_meals;
	uint64_t		last_meal;
}				t_philo;

typedef struct s_data
{
	t_philo			*philos;

	int				eating; // flags? it will communicate with observer
	// should the flags be in philo struct?

	// size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;

	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*dead_lock; //status ?
	pthread_mutex_t	*fork_lock; //status ?
}				t_data;

// program??
// pthread_mutex_t	write_lock;
// pthread_mutex_t	dead_lock;
// pthread_mutex_t	meal_lock;

// treat arguments
int		ft_atoi(char *str);

// Initializing the program structure
void	init_t_data(int argc, char ** argv);
t_data	*data(void);

// Create threads and routine
void    create_philos();
int		philo_data(int index);
void	*routine(void *philo);
// void    *routine2(void *add);

// Routine actions
void    think(t_philo *philo);
void    eat(t_philo *philo);

// Free memory and destroy mutexes

// Utility functions
void    print_thread_execution(t_philo *philo, char *message);
time_t  current_time();

#endif