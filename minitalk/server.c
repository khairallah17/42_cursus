/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:32:21 by mkhairal          #+#    #+#             */
/*   Updated: 2023/06/01 12:04:27 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int sig, siginfo_t *signal, void *test)
{
	static pid_t	user_pid;
	static char		result;
	static int		position;

	(void)test;
	if (user_pid == 0 || signal->si_pid != user_pid)
	{
		result = (char)255;
		position = 0;
		user_pid = signal->si_pid;
	}
	if (sig == SIGUSR1)
		result = result | 128 >> position++;
	else
		result = result ^ 128 >> position++;
	if (position == 8)
	{
		if (result <= 127)
			write(1, &result, 1);
		position = 0;
		result = (char)255;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;
	char				*s;

	sa.sa_sigaction = &handle;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	s = ft_itoa(pid);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
