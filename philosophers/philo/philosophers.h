/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:15:17 by mkhairal          #+#    #+#             */
/*   Updated: 2023/07/29 23:58:13 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>


typedef struct h_details {
	int				lte;
	int				lts;
	int				hma;
	int				index;
}	t_details;

typedef struct h_philo {
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	long			start;
	struct timeval	tv;
	pthread_t		*philos;
	pthread_mutex_t *forks;
	t_details		details;
}	t_philo;

void	*philo_routine(void	*arg);
int		initialize_threads_mutex(t_philo *philo);
int		destoy_mutexes(pthread_mutex_t *muts, int nom);
void	eating(t_philo *philo, int pos);
void	philo_printf(char *string, t_philo *philo, int pos);
void	*philo_routine(void	*arg);
long	get_time(struct timeval tv);
int		join_threads(t_philo *philo);

#endif
