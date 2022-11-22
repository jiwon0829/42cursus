/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hub2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:08 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:06:47 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hub_di(t_info *info, va_list ap)
{
	int	arg_int;
	int	arg_size;
	int	sign;

	arg_int = va_arg(ap, int);
	arg_size = get_decimal_len(info, arg_int);
	if (arg_int == 0)
		sign = 0;
	else
		sign = arg_int;
	if (info->minus)
	{
		if (put_sign(info, arg_int) || put_precision(info, arg_size) || \
		put_decimal(info, arg_int) || put_base_blank(info, arg_size, sign))
			return ;
	}
	else
	{
		if (put_base_blank(info, arg_size, sign) || put_sign(info, arg_int) || \
		put_zero(info, arg_size, sign) || put_precision(info, arg_size) || \
		put_decimal(info, arg_int))
			return ;
	}
}

void	ft_hub_u(t_info *info, va_list ap)
{
	unsigned int	arg_int;
	int				arg_size;
	int				sign;

	arg_int = va_arg(ap, unsigned int);
	arg_size = get_decimal_len(info, arg_int);
	if (arg_int == 0)
		sign = 0;
	else
		sign = 1;
	if (info->minus)
	{
		if (put_precision(info, arg_size) || put_decimal(info, arg_int) || \
		put_base_blank(info, arg_size, sign))
			return ;
	}
	else
	{
		if (put_base_blank(info, arg_size, sign) || \
		put_zero(info, arg_size, 1) || put_precision(info, arg_size) \
		|| put_decimal(info, arg_int))
			return ;
	}
}

void	ft_hub_hexa(t_info *info, unsigned long long arg_hex)
{
	int	arg_size;
	int	sign;

	arg_size = get_hexa_len(info, arg_hex);
	if (arg_hex == 0)
		sign = 0;
	else
		sign = 1;
	if (info->minus)
	{
		if (put_hash(info, arg_hex) || put_precision(info, arg_size) || \
		put_hexa(info, arg_hex) || put_base_blank(info, arg_size, sign))
			return ;
	}
	else
	{
		if (put_base_blank(info, arg_size, sign) || put_hash(info, arg_hex) || \
		put_zero(info, arg_size, sign) || put_precision(info, arg_size) || \
		put_hexa(info, arg_hex))
			return ;
	}
}

void	set_hexa(t_info *info, va_list ap)
{
	unsigned long long	arg_hex;

	if (info->type == 'p')
		arg_hex = (unsigned long long)va_arg(ap, void *);
	else
		arg_hex = va_arg(ap, unsigned int);
	ft_hub_hexa(info, arg_hex);
}
