/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:14 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 16:44:01 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hub_percent(t_info *info)
{
	int	i;

	i = 0;
	if (!info->minus)
	{
		while (i++ < info->width - 1)
		{
			if (ft_putchar(info, ' ') == -1)
				return ;
		}
		if (ft_putchar(info, '%') == -1)
			return ;
	}
	else
	{
		if (ft_putchar(info, '%') == -1)
			return ;
		while (i++ < info->width - 1)
		{
			if (ft_putchar(info, ' ') == -1)
				return ;
		}
	}
}

void	ft_hub_c(t_info *info, va_list ap)
{
	char	arg_c;
	int		i;

	arg_c = va_arg(ap, int);
	i = 0;
	if (!info->minus)
	{
		while (i++ < info->width - 1)
		{
			if (ft_putchar(info, ' ') == -1)
				return ;
		}
		if (ft_putchar(info, arg_c) == -1)
			return ;
	}
	else
	{
		if (ft_putchar(info, arg_c) == -1)
			return ;
		while (i++ < info->width - 1)
		{
			if (ft_putchar(info, ' ') == -1)
				return ;
		}
	}
}

void	ft_hub_s(t_info *info, char *arg_s)
{
	int	arg_size;

	arg_size = set_s_len(info, arg_s);
	if (info->minus)
	{
		if (put_str(info, arg_s, arg_size))
			return ;
		put_s_blank(info, arg_size);
	}
	else
	{
		if (put_s_blank(info, arg_size))
			return ;
		put_str(info, arg_s, arg_size);
	}
}

void	set_s(t_info *info, va_list ap)
{
	char	*arg_s;
	int		chk_null;

	arg_s = va_arg(ap, char *);
	chk_null = 0;
	if (!arg_s)
	{
		arg_s = malloc(7);
		if (!arg_s)
			return ;
		chk_null = 1;
		ft_strlcpy(arg_s, "(null)", 7);
	}
	ft_hub_s(info, arg_s);
	if (chk_null)
		ft_free(arg_s);
}
