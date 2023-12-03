/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:26:43 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/02 22:50:45 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void    milliseconds_to_time(time_t milliseconds)
{
    time_t  seconds;
    time_t  minutes;
    time_t  hours;
    
    seconds = milliseconds / 1000;
    minutes = seconds / 60;
    hours = minutes / 60;
    seconds = seconds % 60;
    minutes = minutes % 60;
    hours = hours % 12;
    printf("\e[1;48;5;129m %lu:%lu:%lu \e[0m\n", hours, minutes, seconds);
}

// current time in milliseconds
// 1 second = 1000 milliseconds
// 1 millisecond = 0.001 seconds
// struct timezone is obsolete, that is why second arg is NULL
// time_t is a type to store time values, like a long int
// since the Epoch, 1970-01-01 00:00:00 +0000 (UTC).
time_t  current_time()
{
    struct timeval  time;

    if (gettimeofday(&time, NULL) == -1)
        printf("%s", TIME_ERROR);
    // printf("current time: %lu\n", ((time.tv_sec * 1000) + (time.tv_usec / 1000)));
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));   
}

/* ************************************************************************** */

// guarantee that each message will be printed once at a time
// control when each activity is being executed (time stamp)
void    print_thread_execution(t_philo *philo, char *message)
{
    pthread_mutex_init(&data()->write_lock, NULL);
    pthread_mutex_lock(&data()->write_lock);
    printf("\e[1;48;5;027m %i %s \e[0m", philo->id, message);
    printf("\e[1;30;48;5;226m %lu \e[0m", current_time() - data()->start_time);
    milliseconds_to_time(current_time());
    pthread_mutex_unlock(&data()->write_lock);
}

// free memory
//pthread_mutex_destroy