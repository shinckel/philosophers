/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:26:43 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/07 22:00:57 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void    milliseconds_to_time(time_t milliseconds)
// {
//     time_t  seconds;
//     time_t  minutes;
//     time_t  hours;
// 
//     seconds = milliseconds / 1000;
//     minutes = seconds / 60;
//     hours = minutes / 60;
//     seconds = seconds % 60;
//     minutes = minutes % 60;
//     hours = hours % 12;
//     printf("%s %lu:%lu:%lu %s\n", CYAN, hours, minutes, seconds, RESET);
// }
// current time in milliseconds
// 1 second = 1000 milliseconds
// 1 millisecond = 0.001 seconds
// struct timezone is obsolete, that is why second arg is NULL
// time_t is a type to store time values, like a long int
// since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
time_t	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("%s", TIME_ERROR);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

/* ************************************************************************** */
// guarantee that each message will be printed once at a time
// control when each activity is being executed (time stamp)
// zu is the placeholder for size_t
void	print_thread_execution(t_philo *philo, char *message, char *color)
{
	size_t	time;

	time = current_time() - data()->start_time;
	pthread_mutex_lock(philo->write_lock);
	if (!dead_loop(philo))
		printf("%s%zu %d%s%s %s%s\n", YELLOW, time, philo->id, RESET,
			color, message, RESET);
	pthread_mutex_unlock(philo->write_lock);
}

void	destory_all(char *str)
{
	int	i;

	i = -1;
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&data()->o_write_lock);
	pthread_mutex_destroy(&data()->o_meal_lock);
	pthread_mutex_destroy(&data()->o_dead_lock);
	while (++i < data()->num_of_philos)
		pthread_mutex_destroy(&data()->forks[i]);
	free(data()->philos);
	free(data()->forks);
}
