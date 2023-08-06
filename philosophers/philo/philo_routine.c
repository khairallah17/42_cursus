/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:21:01 by mkhairal          #+#    #+#             */
/*   Updated: 2023/08/06 15:10:53 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_details *details, int pos)
{
	int	left_fork;
	int	right_fork;

	left_fork = pos;
	right_fork = (pos + 1) % details->philo->nop;
	pthread_mutex_lock(&details->philo->forks[left_fork]);
	philo_printf("has taken a fork", details->philo, pos, 1);
	pthread_mutex_lock(&details->philo->forks[right_fork]);
	philo_printf("has taken a fork", details->philo, pos, 1);
	philo_printf("is eating", details->philo, pos, 1);
	pthread_mutex_lock(&details->philo->lte);
	details->lte = get_time();
	pthread_mutex_unlock(&details->philo->lte);
	sleepy_head(details->philo->tte);
	pthread_mutex_unlock(&details->philo->forks[left_fork]);
	pthread_mutex_unlock(&details->philo->forks[right_fork]);
}

int	died(t_details *details)
{
	long long			now;

	pthread_mutex_lock(&details->philo->lte);
	now = get_time() - details->lte;
	pthread_mutex_unlock(&details->philo->lte);
	if (now > details->philo->ttd)
	{
		philo_printf("died", details->philo, details->index, 0);
		details->philo->dead = 1;
		return (0);
	}
	return (1);
}

void	sleeping(t_details *details, int pos)
{
	philo_printf("is sleeping", details->philo, pos, 1);
	details->lts = get_time();
	sleepy_head(details->philo->tts);
}

void	philo_printf(char *string, t_philo *philo, int pos, int flag)
{
	pthread_mutex_lock(&philo->print_lock);
	printf("%lld %d ", get_time() - philo->start, pos + 1);
	printf("%s\n", string);
	if (flag)
		pthread_mutex_unlock(&philo->print_lock);
}

void	*philo_routine(void	*arg)
{
	t_details	*details;

	details = (t_details *)arg;
	details->hma = 0;
	while (1)
	{
		eating(details, details->index);
		sleeping(details, details->index);
		philo_printf("is thinking", details->philo, details->index, 1);
		details->hma++;
		pthread_mutex_lock(&details->philo->death);
		if (details->hma == details->philo->hme)
			details->philo->noe += 1;
		pthread_mutex_unlock(&details->philo->death);
	}
	return (NULL);
}
