/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:57:24 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/09/18 17:23:41 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_info
{
	char	type;
	int		width;
	int		is_pre;
	int		precision;
	int		minus;
	int		plus;
	int		zero;
	int		hash;
	int		space;
	int		total_len;
}				t_info;

int		ft_printf(const char *format, ...);
int		parsing_format(const char **format, va_list ap);
int		print_type(t_info *info, va_list ap);
int		total_len(int error, int len);

void	init_info(t_info *info);
void	set_info(t_info *info, const char **format);
void	kind_zero_info(t_info *info);
void	*ft_free(void *ptr);
int		ft_putchar(t_info *info, char c);

void	ft_hub_percent(t_info *info);
void	ft_hub_c(t_info *info, va_list ap);
void	ft_hub_s(t_info *info, char *arg_s);
void	set_s(t_info *info, va_list ap);
void	ft_hub_di(t_info *info, va_list ap);
void	ft_hub_u(t_info *info, va_list ap);
void	ft_hub_hexa(t_info *info, unsigned long long arg_hex);
void	set_hexa(t_info *info, va_list ap);

int		put_str(t_info *info, char *arg_s, int arg_size);
int		set_s_len(t_info *info, char *arg_s);
int		put_s_blank(t_info *info, int size);

int		put_sign(t_info *info, int arg_int);
int		put_hash(t_info *info, unsigned long long arg_hex);
int		put_zero(t_info *info, int arg_size, int sign);
int		put_precision(t_info *info, int arg_size);
int		put_base_blank(t_info *info, int size, int sign);

int		get_decimal_len(t_info *info, long nb);
int		put_decimal(t_info *info, long nb);
int		get_hexa_len(t_info *info, unsigned long long ll);
int		put_hexa(t_info *info, unsigned long long ll);

#endif
