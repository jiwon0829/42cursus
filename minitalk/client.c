/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:06 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/22 17:17:39 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(pid_t s_pid, char *msg)
{
	size_t	i;
	int		bit;

	i = 0;
	while (msg[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((msg[i] >> bit) & 1)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			usleep(100);
			bit--;
		}
		i++;
	}
	while (bit-- <= 6)
	{
		kill(s_pid, SIGUSR2);
		usleep(100);
	}
}

static void	ft_handler(int sig)
{
	if (sig == SIGUSR2)
		print_send_message("Server received your message\n");
	exit (0);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, s1_len + 1);
	ft_strlcpy(&ptr[s1_len], s2, s2_len + 1);
	return (ptr);
}

int	main(int ac, char *av[])
{
	pid_t	server_pid;

	if (ac == 3 && ft_strlen(av[2]))
	{
		signal(SIGUSR2, ft_handler);
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			print_error_message("Invalid server pid entered.\n");
			return (0);
		}
		send_signal(server_pid, ft_strjoin(av[2], "\n"));
		while (1)
			pause();
	}
	else
		print_error_message("Argument is not 3.\n");
	return (0);
}
