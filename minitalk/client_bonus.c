/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:38:17 by mkhairal          #+#    #+#             */
/*   Updated: 2023/05/31 22:20:39 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(pid_t pid, char *message)
{
	int	i;
	int	send;

	i = 0;
	while (message[i])
	{
		send = 0;
		while (send < 8)
		{
			if ((message[i] & 128 >> send) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
			send++;
		}
		i++;
	}
	send = 0;
	while (send < 8)
	{
		kill(pid, SIGUSR2);
		send++;
		usleep(800);
	}
}

void	received__message(int sig)
{
	if (sig == SIGUSR2)
		write(1, "-----------MESSAGE RECEIVED-----------", 39);
}

int	main(int argc, char *argv[])
{
	pid_t				pid;
	struct sigaction	sigact;

	if (argc < 3)
	{
		write(1, "missing arguments needed!!", 27);
	}
	else
	{
		if (check_pid(argv[1]) == 1)
			write(1, "invalid PID !", ft_strlen("invalid PID !"));
		else
		{
			sigact.sa_handler = &received__message;
			sigact.sa_flags = 0;
			sigaction(SIGUSR2, &sigact, NULL);
			pid = ft_atoi(argv[1]);
			send_message(pid, argv[2]);
		}
	}
	return (0);
}
