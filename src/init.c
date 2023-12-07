/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:20:50 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/07 12:22:44 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
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
void	init_t_data(int argc, char ** argv)
{
	data()->num_of_philos = ft_atoi(argv[1]);
	data()->time_to_die = ft_atoi(argv[2]);
	data()->time_to_eat = ft_atoi(argv[3]);
	data()->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data()->num_times_to_eat = ft_atoi(argv[5]);
	else
		data()->num_times_to_eat = -1;
	printf("you have %d philos!!\n", data()->num_of_philos);
	printf("you will die on %zu\n", data()->time_to_die);
	printf("you will eat on %zu\n", data()->time_to_eat);
	printf("you will sleep on %zu\n", data()->time_to_sleep);
	printf("please eat %d times\n", data()->num_times_to_eat);
}
