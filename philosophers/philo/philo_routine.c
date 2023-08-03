/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:21:01 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/30 00:03:01 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void eating(t_philo *philo, int pos) {
    int left_fork;
    int right_fork;

	left_fork = pos;
	right_fork = (pos + 1) % philo->nop;
    pthread_mutex_lock(&philo->forks[left_fork]);
    philo_printf("has taken a fork", philo, pos);
    pthread_mutex_lock(&philo->forks[right_fork]);
    philo_printf("has taken a fork", philo, pos);
    usleep(philo->tte);
    philo->start += philo->tte;
    pthread_mutex_unlock(&philo->forks[left_fork]);
    pthread_mutex_unlock(&philo->forks[right_fork]);
}

void	died(t_philo *philo)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = get_time(tv) - philo->start;
	// printf("current time ==> %ld\n", now);
}

void	sleeping(t_philo *philo, int pos)
{
	philo_printf("is sleeping", philo, pos);
	usleep(philo->tts);
	philo->start += philo->tts;
}

void	philo_printf(char *string, t_philo *philo, int pos)
{
	pthread_mutex_t	print_lock;

	pthread_mutex_init(&print_lock, NULL);
	pthread_mutex_lock(&print_lock);
	printf("%ld %d ", philo->start, pos);
	printf("%s\n", string);
	pthread_mutex_unlock(&print_lock);
	pthread_mutex_destroy(&print_lock);
}

void	*philo_routine(void	*arg)
{
	t_philo	*philo;
	int		i = 0;

	philo = (t_philo *)arg;
	while (1)
	{
		printf("CURRENT THREAD ==> %ld\n", pthread_self());
		eating(philo, i % (philo->nop + 1));
		sleeping(philo, i % (philo->nop + 1));
		philo_printf("is thinking", philo, i % (philo->nop + 1));
		usleep(1);
		i++;
		// died(philo);
	}
}
