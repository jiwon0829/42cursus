/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:42:36 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/11/21 18:39:57 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	itoc(int num, int fd)
{
	int	tmp;

	tmp = num % 10;
	if (!num)
		return ;
	num /= 10;
	itoc(num, fd);
	ft_putchar_fd('0' + tmp, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	long long	tmp;

	if (fd < 0)
		return ;
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	tmp = num % 10;
	itoc(num / 10, fd);
	ft_putchar_fd('0' + tmp, fd);
}

static int	ft_range_check(char const *str, size_t i, int sign)
{
	unsigned long long	val;
	unsigned long long	res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = res;
		res = res * 10 + (str[i] - '0');
		if (val > res && sign == -1)
			return (0);
		else if (val > res && sign == 1)
			return (-1);
		++i;
	}
	return (sign * res);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	return (ft_range_check(str, i, sign));
}
