/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:20:50 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/25 12:34:52 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializing the program structure
// death status
	// init mutex? death.lock
	// number of philos ------ OK
	// time for dying ------ OK
	// time for eating ------ OK
	// time fot sleep ------ OK
	// 5 or 6 arguments? number of times for eat, or INT_MAX ------ OK
	// data start get_time()
	// init mutex? data print
	// data->death = death
void	init_t_data(int argc, char ** argv, t_data *data)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->num_times_to_eat = ft_atoi(argv[5]);
	else
		data->num_times_to_eat = INT_MAX;
	printf("you have %d philos!!\n", data->num_of_philos);
	printf("you will die on %zu\n", data->time_to_die);
	printf("you will eat on %zu\n", data->time_to_eat);
	printf("you will sleep on %zu\n", data->time_to_sleep);
	printf("please eat %d times\n", data->num_times_to_eat);
}

// Initializing the forks mutexes

// Initializing the philosophers

// Initializing the input from user