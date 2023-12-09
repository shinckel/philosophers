/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:24:43 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/09 17:11:25 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_thread_execution(philo, THINK, ORANGE);
}

void	dream(t_philo *philo)
{
	print_thread_execution(philo, DREAM, BLUE);
	ft_usleep(data()->time_to_sleep);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_thread_execution(philo, FORK_R, PURPLE);
	if (data()->num_of_philos == 1)
	{
		ft_usleep(data()->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_thread_execution(philo, FORK_L, PURPLE);
	philo->eating_flag = 1;
	print_thread_execution(philo, EAT, PURPLE);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time();
	philo->n_meals++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(data()->time_to_eat);
	philo->eating_flag = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}
