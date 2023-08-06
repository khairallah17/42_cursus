/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_mutexes_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:27:09 by mkhairal          #+#    #+#             */
/*   Updated: 2023/08/06 13:45:07 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initialize_mutex(t_philo *philo)
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
	created = pthread_mutex_init(&philo->print_lock, NULL);
	pthread_mutex_init(&philo->lte, NULL);
	if (created != 0)
		return (0);
	return (1);
}

int	initialize_threads(t_philo *philo)
{
	int	i;
	int	created;

	i = 0;
	created = 0;
	philo->start = get_time();
	while (i < philo->nop)
	{
		memset(&philo->details[i], 0, sizeof(philo->details[i]));
		philo->details[i].index = i;
		philo->details[i].lte = philo->start;
		philo->details[i].philo = philo;
		philo->details[i].hma = 0;
		created = pthread_create(&philo->philos[i], NULL, &philo_routine, \
		&philo->details[i]);
		if (created != 0)
			return (0);
		pthread_detach(philo->philos[i]);
		if (i % 2 == 0)
			sleepy_head(1);
		i++;
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
	return (1);
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
