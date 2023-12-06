/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:43 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/06 16:17:55 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    think(t_philo *philo)
{
    print_thread_execution(philo, THINK, PINK);
}

void	dream(t_philo *philo)
{
	print_thread_execution(philo, DREAM, BLUE);
	ft_usleep(data()->time_to_sleep);
}

/*
Now to the eating part, We will lock the right fork first using pthread_mutex_lock and
print the message, and do the same with the left fork. Then he will eat using ft_usleep 
again and only then he will drop the forks by unlocking the locks, before that we change 
some variables that give our monitor indications but that’s the general idea.
*/

void    eat(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print_thread_execution(philo, FORK_R, PURPLE);
    pthread_mutex_lock(philo->l_fork);
    print_thread_execution(philo, FORK_L, PURPLE);
    philo->eating_flag = 1;
    print_thread_execution(philo, EAT, PURPLE);
    pthread_mutex_lock(philo->meal_lock);
    philo->last_meal = current_time();
    philo->n_meals++;
    pthread_mutex_unlock(philo->meal_lock);
    usleep(data()->time_to_eat);
    philo->eating_flag = 1;
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}
