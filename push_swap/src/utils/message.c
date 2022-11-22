/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:47:28 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:34:05 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	message_not_integer(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	message_overlap(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	message_memory(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
