/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhairal <mkhairal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:56:34 by mkhairal          #+#    #+#             */
/*   Updated: 2023/05/31 22:20:48 by mkhairal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = s;
	if (!n)
		return ;
	while (n--)
		*(t++) = 0;
}

void	check_value(t_unicode *uc)
{
	if (uc->cv == 0)
		kill(uc->cpid, SIGUSR2);
	else
	{
		if (uc->cv <= 128)
			write(1, &uc->cv, 1);
		else if (uc->cv >= 192 && uc->cv < 224)
			uc->nob = 2;
		else if (uc->cv >= 224 && uc->cv < 240)
			uc->nob = 3;
		else if (uc->cv >= 240)
			uc->nob = 4;
		if (uc->ac < uc->nob)
			uc->res[uc->ac++] = uc->cv;
		if (uc->ac == uc->nob)
		{
			write(1, &uc->res, uc->ac);
			uc->nob = 0;
			uc->ac = 0;
			ft_bzero(uc->res, 4);
		}
	}
	uc->cv = (char)255;
	uc->cp = 0;
}

void	handle(int sig, siginfo_t *sign, void *test)
{
	static t_unicode	uc;

	(void)test;
	if (uc.cpid == 0 || sign->si_pid != uc.cpid)
	{
		uc.cv = (char)255;
		uc.cp = 0;
		uc.cpid = sign->si_pid;
		uc.ac = 0;
		ft_bzero(uc.res, 4);
		uc.nob = 0;
	}
	if (sig == SIGUSR1)
		uc.cv = uc.cv | 128 >> uc.cp++;
	else
		uc.cv = uc.cv ^ 128 >> uc.cp++;
	if (uc.cp == 8)
		check_value(&uc);
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
