/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:14:03 by mkhairal          #+#    #+#             */
/*   Updated: 2023/08/06 15:20:52 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*death_check(void	*arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1337)
	{
		i = 0;
		while (i < philo->nop)
		{
			pthread_mutex_lock(&philo->death);
			if (philo->noe == philo->nop)
			{
				pthread_mutex_lock(&philo->print_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->death);
			if (!died(&philo->details[i]))
				return (NULL);
		}
		usleep(200);
	}
	return (NULL);
}

int	checker(t_philo *philo)
{
	pthread_t	death_checker;
	int			i;
	int			created;

	i = 0;
	created = 0;
	created = pthread_create(&death_checker, NULL, &death_check, philo);
	if (created != 0)
		return (0);
	pthread_join(death_checker, NULL);
	return (1);
}

void	initializer(t_philo *philosophers)
{
	philosophers->philos = (pthread_t *)malloc(\
	sizeof(pthread_t) * philosophers->nop);
	philosophers->forks = (pthread_mutex_t *)malloc(\
	sizeof(pthread_mutex_t) * (philosophers->nop));
	philosophers->details = malloc(\
	sizeof(t_details) * philosophers->nop);
	initialize_mutex(philosophers);
	initialize_threads(philosophers);
	checker(philosophers);
	destoy_mutexes(philosophers->forks, philosophers->nop);
	free(philosophers->philos);
	free(philosophers->forks);
	free(philosophers);
}

int	main(int ac, char **av)
{
	t_philo	*philosophers;

	philosophers = (t_philo *)malloc(sizeof(t_philo));
	philosophers->nop = ft_atoi(av[1]);
	philosophers->ttd = ft_atoi(av[2]);
	philosophers->tte = ft_atoi(av[3]);
	philosophers->tts = ft_atoi(av[4]);
	philosophers->dead = 0;
	philosophers->noe = 1;
	if (ac == 5)
	{
		philosophers->hme = -1;
		initializer(philosophers);
	}
	else if (ac == 6)
	{
		philosophers->hme = ft_atoi(av[5]);
		initializer(philosophers);
	}
}
