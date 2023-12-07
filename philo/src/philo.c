/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:21:15 by shinckel          #+#    #+#             */
/*   Updated: 2023/12/07 22:08:25 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

// convert a string into integer
// check if there are forbidden characters
long long	ft_atoll(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	if (*str && !(*str >= '0' && *str <= '9'))
		return (0);
	return (res * sign);
}

// check if input value is correct
// is it empty (NULL)? is it a positive number?
// is it a number between INT_MIN and INT_MAX?
// is it a number between 1 and 200 (MAX_PHILO)?
int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < argc)
	{
		if (argv[i] == NULL)
			return (1);
		if (i == 1 && ft_atoll(argv[i]) > MAX_PHILO)
			return (1);
		if (ft_atoll(argv[i]) <= 0
			|| (ft_atoll(argv[i]) > INT_MAX || ft_atoll(argv[i]) < INT_MIN))
			return (1);
		i++;
	}
	return (0);
}

static int	init_observer_philos_forks(void)
{
	int	i;

	i = -1;
	data()->philos = malloc(sizeof(t_philo) * data()->num_of_philos);
	data()->forks = malloc(sizeof(pthread_mutex_t) * data()->num_of_philos);
	pthread_mutex_init(&data()->o_dead_lock, NULL);
	pthread_mutex_init(&data()->o_meal_lock, NULL);
	pthread_mutex_init(&data()->o_write_lock, NULL);
	data()->dead_flag = 0;
	if (!data()->philos)
		return (1);
	while (++i < data()->num_of_philos)
		pthread_mutex_init(&data()->forks[i], NULL);
	return (0);
}

// 5 args - number of philos, time die, time eat, time sleep, number of meals
// time die - time to die in milliseconds if philo doesnt eat
int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
	{
		printf(WRONG_ARGS);
		return (1);
	}
	init_t_data(argc, argv);
	if (init_observer_philos_forks())
		destory_all(NULL);
	philo_data();
	create_philos();
	destory_all(NULL);
	return (0);
}
