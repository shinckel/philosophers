/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:20:36 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/06 16:17:25 by shinckel         ###   ########.fr       */
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

// colors
# define RED "\e[1;41m"
# define BLUE "\e[1;48;5;027m"
# define GREEN "\e[1;42m"
# define YELLOW "\e[1;48;5;226m"
# define PURPLE "\e[1;48;5;129m"
# define CYAN "\e[1;48;5;051m"
# define WHITE "\e[1;48;5;255m"
# define ORANGE "\e[1;48;5;208m"
# define PINK "\e[1;48;5;213m"
# define RESET "\e[0m"
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
# define DEAD "is dead..."

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				n_meals;
	uint64_t		last_meal;
	int				dead_flag;
	int				eating_flag;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}				t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_t		observer;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;

	pthread_mutex_t	*forks;
	pthread_mutex_t	o_dead_lock;
	pthread_mutex_t o_meal_lock;
	pthread_mutex_t	o_write_lock;
}				t_data;

// treat arguments
int		ft_atoi(char *str);

// Initializing the program structure
void	init_t_data(int argc, char ** argv);
t_data	*data(void);

// Create threads and routine
void    create_philos();
int		philo_data(int index);
void	*routine(void *philo);
void    *observe(void *philo);

// Routine actions
void    think(t_philo *philo);
void    eat(t_philo *philo);
void	dream(t_philo *philo);

// Free memory and destroy mutexes

// Utility functions
void    print_thread_execution(t_philo *philo, char *message, char *color);
time_t  current_time();
int		ft_usleep(size_t milliseconds);

#endif