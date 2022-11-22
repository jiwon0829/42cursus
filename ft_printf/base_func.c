/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:03:52 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:09:29 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_decimal_len(t_info *info, long nb)
{
	int		len;

	len = 0;
	if (nb == 0 && info->is_pre && !(info->precision))
		return (0);
	else if (nb == 0)
		return (1);
	else if (nb < 0)
		nb = -nb;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	put_decimal(t_info *info, long nb)
{
	char	c;

	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		put_decimal(info, nb / 10);
	c = (nb % 10) + '0';
	if (!(info->is_pre && info->precision == 0 && nb == 0))
	{
		if (ft_putchar(info, c) == -1)
			return (1);
	}
	return (0);
}

int	get_hexa_len(t_info *info, unsigned long long ll)
{
	int	len;

	len = 0;
	if (ll == 0 && info->is_pre && !(info->precision))
		return (0);
	else if (ll == 0)
		return (1);
	while (ll)
	{
		ll /= 16;
		++len;
	}
	return (len);
}

int	put_hexa(t_info *info, unsigned long long ll)
{
	char	c;

	if (ll >= 16)
		put_hexa(info, (ll / 16));
	if ((ll % 16) >= 10 && (info->type == 'x' || info->type == 'p'))
		c = 'a' + (ll % 16) - 10;
	else if ((ll % 16) >= 10 && info->type == 'X')
		c = 'A' + (ll % 16) - 10;
	else
		c = '0' + (ll % 16);
	if (!(info->is_pre && info->precision == 0 && ll == 0))
	{
		if (ft_putchar(info, c) == -1)
			return (1);
	}
	return (0);
}
