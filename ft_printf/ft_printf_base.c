/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:11 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:14:58 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_sign(t_info *info, int arg_int)
{
	if (arg_int < 0)
	{
		if (ft_putchar(info, '-') == -1)
			return (1);
	}
	else if (info->plus)
	{
		if (ft_putchar(info, '+') == -1)
			return (1);
	}
	else if (info->space)
	{
		if (ft_putchar(info, ' ') == -1)
			return (1);
	}
	return (0);
}

int	put_hash(t_info *info, unsigned long long arg_hex)
{
	if (info->type == 'p' || (arg_hex && info->hash))
	{
		if (info->type == 'X')
		{
			if (ft_putchar(info, '0') == -1)
				return (1);
			if (ft_putchar(info, 'X') == -1)
				return (1);
		}
		else
		{
			if (ft_putchar(info, '0') == -1)
				return (1);
			if (ft_putchar(info, 'x') == -1)
				return (1);
		}
	}
	return (0);
}

int	put_zero(t_info *info, int arg_size, int sign)
{
	if (sign < 0)
		++arg_size;
	else if (info->plus || info->space)
		++arg_size;
	if ((sign != 0 && info->hash) || info->type == 'p')
		arg_size += 2;
	if (info->zero && !info->is_pre && info->width > arg_size)
	{
		while (info->width > arg_size++)
		{
			if (ft_putchar(info, '0') == -1)
				return (1);
		}
	}
	return (0);
}

int	put_precision(t_info *info, int arg_size)
{
	if (info->is_pre && info->precision > arg_size)
	{
		while (arg_size++ < info->precision)
		{
			if (ft_putchar(info, '0') == -1)
				return (1);
		}
	}
	return (0);
}

int	put_base_blank(t_info *info, int size, int sign)
{
	if (info->is_pre && info->precision > size)
		size = info->precision;
	if (sign < 0)
		++size;
	else if (info->plus || info->space)
		++size;
	if (((info->type == 'x' || info->type == 'X') && info->hash \
	&& sign != 0) || info->type == 'p')
		size += 2;
	if ((info->is_pre && info->width > info->precision) \
	|| (!info->is_pre && info->width > size && !info->zero))
	{
		while (size++ < info->width)
		{
			if (ft_putchar(info, ' ') == -1)
				return (1);
		}
	}
	return (0);
}
