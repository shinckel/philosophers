/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:43 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/02 23:51:55 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    think(t_philo *philo)
{
    print_thread_execution(philo, THINK);
}

/*
Now to the eating part, We will lock the right fork first using pthread_mutex_lock and
print the message, and do the same with the left fork. Then he will eat using ft_usleep 
again and only then he will drop the forks by unlocking the locks, before that we change 
some variables that give our monitor indications but that’s the general idea.
*/

void    eat(t_philo *philo)
{
    pthread_mutex_lock(&data()->fork_lock[philo->id - 1]);
    print_thread_execution(philo, FORK_L);
    pthread_mutex_lock(&data()->fork_lock[philo->id % data()->num_of_philos]);
    print_thread_execution(philo, FORK_R);
    data()->eating = 1; //flag
    print_thread_execution(philo, EAT);
    pthread_mutex_lock(&data()->meal_lock);
    philo->last_meal = current_time();
    philo->n_meals++;
    pthread_mutex_unlock(&data()->meal_lock);
    sleep(data()->time_to_eat);
    // usleep(data()->time_to_eat * 1); //update this code
    data()->eating = 0; // flag
    pthread_mutex_unlock(&data()->fork_lock[philo->id]);
    pthread_mutex_unlock(&data()->fork_lock[philo->id % data()->num_of_philos]);
}

// print_thread_execution(philo, EAT);
//     philo->n_meals++;
//     usleep(data()->time_to_eat * 1000);

// void	*routine(void *action)
// {
// 	// int		time_to_die;
// 	// int		time_to_eat;
// 	// int		time_to_sleep;
// }