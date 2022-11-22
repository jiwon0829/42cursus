/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:19 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 16:50:41 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < sizeof(t_info))
		((unsigned char *)info)[i++] = 0;
}

void	kind_zero_info(t_info *info)
{
	if (info->is_pre)
		info->precision *= 10;
	else if (info->width)
		info->width *= 10;
	else
		info->zero = 1;
}

void	set_info(t_info *info, const char **format)
{
	if (**format == '0')
		kind_zero_info(info);
	else if (ft_strchr("-+# .", **format))
	{
		if (**format == '-')
			info->minus = 1;
		else if (**format == '+')
			info->plus = 1;
		else if (**format == '#')
			info->hash = 1;
		else if (**format == ' ')
			info->space = 1;
		else if (**format == '.')
			info->is_pre = 1;
	}
	else if (ft_strchr("123456789", **format))
	{
		if (info->is_pre)
			info->precision = (info->precision * 10) + (**format - '0');
		else
			info->width = (info->width * 10) + (**format - '0');
	}
}

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

int	ft_putchar(t_info *info, char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		info->total_len = -1;
	info->total_len += result;
	return (result);
}
