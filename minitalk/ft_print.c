/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:35:05 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/21 22:00:44 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (ft_strlen(src));
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

void	print_error_message(char *msg)
{
	size_t	len;

	len = ft_strlen(msg);
	write(2, msg, len);
	exit(1);
}

void	print_pid(pid_t pid)
{
	write(1, "SERVER PID : ", 13);
	itoc(pid, 1);
	write(1, "\n", 1);
}

void	print_send_message(char *msg)
{
	size_t	len;

	len = ft_strlen(msg);
	write(1, msg, len);
}
