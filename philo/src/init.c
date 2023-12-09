/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:20:50 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/09 14:08:32 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// this is a trick to avoid using global variables
// you can call the function and use data anywhere
t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

// Initializing the program structure
// data()->num_times_to_eat = INT_MAX;
void	init_t_data(int argc, char **argv)
{
	data()->num_of_philos = (int)ft_atoll(argv[1]);
	data()->time_to_die = (int)ft_atoll(argv[2]);
	data()->time_to_eat = (int)ft_atoll(argv[3]);
	data()->time_to_sleep = (int)ft_atoll(argv[4]);
	if (argc == 6)
		data()->num_times_to_eat = (int)ft_atoll(argv[5]);
	else
		data()->num_times_to_eat = -1;
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
