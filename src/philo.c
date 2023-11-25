/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:21:15 by shinckel          #+#    #+#             */
/*   Updated: 2023/11/24 15:35:32 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create,
// pthread_detach, pthread_join, pthread_mutex_init,
// pthread_mutex_destroy, pthread_mutex_lock,
// pthread_mutex_unlock

// this is a trick to avoid using global variables
// you can call the function and use data anywhere
t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

// convert a string into integer
// check if there are forbidden characters
int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

// check if input value is correct
// is it empty (NULL)? is it a positive number?
// is it a number between INT_MIN and INT_MAX?
// is it a number between 1 and 200 (MAX_PHILO)?
// why this number is passing? -8888888888883
int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	if (ft_atoi(argv[1]) > MAX_PHILO || ft_atoi(argv[1]) < 1
		|| ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		return (1);
	while (i < argc)
	{
		if (argv[i] == NULL)
			return (1);
		if (ft_atoi(argv[i]) <= 0
			|| (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN))
			return (1);
		//testing purposes -- delete later
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	return (0);
}

//check valid arguments
// philosophers number?
// time to die?
// time to eat?
// time to sleep?
// number of times each philosopher must eat?
// check if input value is correct

int mails = 0;
pthread_mutex_t mutex;

void    *routine()
{ 
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
    return (NULL);
}

int	main(int argc, char **argv)
{
	// check valid arguments
	// numbers of philo
	if (check_args(argc, argv))
	{
		printf(WRONG_ARGS);
		return (1);
	}
	// init program
	// init philo... init forks
	// create threads
	// clean and destroy all

	pthread_t   t1;
	pthread_t   t2;
	int	value0 = 1;
	int	value1 = 2;

	pthread_mutex_init(&mutex, NULL);

    // NULL default attributes
    pthread_create(&t1, NULL, routine, (void *)&value0);
    pthread_create(&t2, NULL, routine, (void *)&value1);

    // wait for thread to terminate
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);

	printf("Total mails: %d\n", mails);
	return (0);
}
