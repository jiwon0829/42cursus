/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:17 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 16:50:08 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(t_info *info, char *arg_s, int arg_size)
{
	int	i;

	i = 0;
	if (!arg_s)
		return (1);
	while (arg_s[i] && i < arg_size)
	{
		if (ft_putchar(info, arg_s[i]) == -1)
			return (1);
		++i;
	}
	return (0);
}

int	set_s_len(t_info *info, char *arg_s)
{
	int	arg_size;

	arg_size = ft_strlen(arg_s);
	if (info->is_pre && info->precision < arg_size)
		arg_size = info->precision;
	return (arg_size);
}

int	put_s_blank(t_info *info, int size)
{
	int	i;

	i = 0;
	if (info->width >= size)
	{
		while (i + size < info->width)
		{
			if (ft_putchar(info, ' ') == -1)
				return (1);
			++i;
		}
	}
	return (0);
}
