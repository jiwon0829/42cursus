/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:34 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/21 18:52:28 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;
	pid_t		pid_c;

	pid_c = info->si_pid;
	(void)context;
	if (sig == SIGUSR1)
		c = c + c | 1;
	else
		c = c << 1;
	bit++;
	if (bit == 8)
	{
		if (c != '\0')
			write(1, &c, 1);
		else
			kill(pid_c, SIGUSR2);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_handler;
	sigemptyset(&sa.sa_mask);
	print_pid(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
