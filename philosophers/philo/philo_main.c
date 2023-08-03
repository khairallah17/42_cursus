/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:14:03 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/30 00:00:38 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(struct timeval tv)
{
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(int ac, char **av)
{
	t_philo	*philosophers;

	philosophers = (t_philo *)malloc(sizeof(t_philo));
	philosophers->nop = 5;
	philosophers->tte = 800;
	philosophers->ttd = 200;
	philosophers->tts = 200;
	philosophers->start = get_time(philosophers->tv);
	philosophers->philos = (pthread_t *)malloc(sizeof(pthread_t) * philosophers->nop);
	philosophers->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philosophers->nop);
	initialize_threads_mutex(philosophers);
	destoy_mutexes(philosophers->forks, philosophers->nop);
	join_threads(philosophers);
	free(philosophers->philos);
	free(philosophers->forks);
	free(philosophers);
}
