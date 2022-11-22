/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:33:18 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:33:20 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_range_check(char const *str, size_t i, int sign)
{
	long long	res;

	res = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			message_not_integer();
		res = res * 10 + (str[i] - '0');
		++i;
	}
	res *= sign;
	if ((res < -2147483648) || (res > 2147483647))
		message_not_integer();
	return (res);
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
	if (!str[i])
		message_not_integer();
	return (ft_range_check(str, i, sign));
}
