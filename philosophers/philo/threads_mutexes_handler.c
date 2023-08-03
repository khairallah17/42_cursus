/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mutexes_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:27:09 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/29 23:44:08 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialize_threads_mutex(t_philo *philo)
{
	int	i;
	int	created;

	i = 0;
	created = 0;
	while (i < philo->nop)
	{
		created = pthread_mutex_init(&philo->forks[i], NULL);
		if (created != 0)
			return (0);
		i++;
	}
	i = 0;
	created = 0;
	while (i < philo->nop)
	{
		philo->details.index = i;
		created = pthread_create(&philo->philos[i], NULL, &philo_routine, philo);
		if (created != 0)
			return (0);
		i++;
		usleep(50);
	}
	return (1);
}

int	destoy_mutexes(pthread_mutex_t *muts, int nom)
{
	int	i;
	int	destoyed;

	i = 0;
	destoyed = 0;
	while (i < nom)
	{
		destoyed = pthread_mutex_destroy(&muts[i++]);
		if (destoyed != 0)
			return (0);
	}
	return 1;
}

int	join_threads(t_philo *philo)
{
	int	i;
	int	joined;

	i = 0;
	joined = 0;
	while (i < philo->nop)
	{
		joined = pthread_join(philo->philos[i], NULL);
		if (joined != 0)
			return (0);
		i++;
	}
	return (1);
}
