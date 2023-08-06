/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:15:17 by mkhairal          #+#    #+#             */
/*   Updated: 2023/08/06 14:32:57 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct h_details {
	long long			lte;
	long long			lts;
	long long			hma;
	int					index;
	struct h_philo		*philo;
}	t_details;

typedef struct h_philo {
	int					nop;
	long long			ttd;
	long long			tte;
	long long			tts; 
	long long			tme;
	long long			hme;
	long long			start;
	int					curr_index;
	int					dead;
	int					noe;
	pthread_mutex_t		lte;
	pthread_mutex_t		hma;
	pthread_mutex_t		death;
	struct timeval		tv;
	pthread_mutex_t		print_lock;
	pthread_t			*philos;
	pthread_mutex_t		*forks;
	t_details			*details;
}	t_philo;

void		*philo_routine(void	*arg);
int			initialize_threads(t_philo *philo);
int			initialize_mutex(t_philo *philo);
int			destoy_mutexes(pthread_mutex_t *muts, int nom);
void		eating(t_details *details, int pos);
void		philo_printf(char *string, t_philo *philo, int pos, int flag);
void		*philo_routine(void	*arg);
long long	get_time(void);
int			join_threads(t_philo *philo);
void		sleepy_head(long sleep);
int			died(t_details *details);
int			ft_atoi(char *nptr);

#endif
