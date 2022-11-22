/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_optimization2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:00:56 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 13:31:07 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_element_sort(t_tool *tool)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i++ < 5)
	{
		tmp = tool->a->top->data;
		if (tmp >= tool->sorted_num[2])
			ra(tool);
		else
			pb(tool);
	}
	only_three_element_a_stack(tool, 2, 4);
	two_element_sort(tool, 'b');
	pa(tool);
	pa(tool);
}
