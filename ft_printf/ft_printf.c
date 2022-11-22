/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:22 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:23:31 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_type(t_info *info, va_list ap)
{
	if (info->type == '%')
		ft_hub_percent(info);
	else if (info->type == 'c')
		ft_hub_c(info, ap);
	else if (info->type == 's')
		set_s(info, ap);
	else if (info->type == 'd' || info->type == 'i')
		ft_hub_di(info, ap);
	else if (info->type == 'u')
		ft_hub_u(info, ap);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		set_hexa(info, ap);
	return (info->total_len);
}

int	parsing_format(const char **format, va_list ap)
{
	int		return_size;
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (-1);
	return_size = -1;
	init_info(info);
	while (ft_strchr("-+0# .123456789", **format))
	{
		set_info(info, format);
		++(*format);
	}
	if (ft_strchr("csxXpdiu%", **format))
	{
		info->type = **format;
		return_size = print_type(info, ap);
		++(*format);
	}
	else
		return_size = -1;
	ft_free(info);
	return (return_size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		return_size;
	int		is_valid;

	va_start(ap, format);
	return_size = 0;
	is_valid = 0;
	while (*format && is_valid != -1)
	{
		if (*format == '%')
		{
			++format;
			is_valid = parsing_format(&format, ap);
		}
		else if (*format != '%')
		{
			is_valid = write(1, format, 1);
			++format;
		}
		if (is_valid != -1)
			return_size += is_valid;
	}
	va_end(ap);
	return (total_len(is_valid, return_size));
}

int	total_len(int error, int len)
{
	if (error == -1)
		return (-1);
	return (len);
}
