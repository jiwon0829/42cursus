/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:08:15 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 14:07:54 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_top_b(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;
	int	i;
	int	tmp;

	if (end - start < 3)
		return (hub_small_b_stack_size(tool, start, end, TOP));
	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	i = 0;
	while (i++ <= end - start)
	{
		tmp = tool->b->top->data;
		if (tmp < tool->sorted_num[small_pivot])
			rb(tool);
		else
		{
			pa(tool);
			if (tmp < tool->sorted_num[big_pivot])
				ra(tool);
		}
	}
	return (recur_top_b(tool, start, end));
}

void	sort_bottom_b(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;
	int	i;
	int	tmp;

	if (end - start < 3)
		return (hub_small_b_stack_size(tool, start, end, BOTTOM));
	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	i = 0;
	while (i++ <= end - start)
	{
		tmp = tool->b->bottom->data;
		rrb(tool);
		if (tmp >= tool->sorted_num[small_pivot])
		{
			pa(tool);
			if (tmp < tool->sorted_num[big_pivot])
				ra(tool);
		}
	}
	return (recur_bottom_b(tool, start, end));
}

void	recur_top_b(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;

	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	sort_top_a(tool, big_pivot, end);
	sort_bottom_a(tool, small_pivot, big_pivot - 1);
	sort_bottom_b(tool, start, small_pivot - 1);
}

void	recur_bottom_b(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;

	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	sort_top_a(tool, big_pivot, end);
	sort_bottom_a(tool, small_pivot, big_pivot - 1);
	sort_top_b(tool, start, small_pivot - 1);
}

void	hub_small_b_stack_size(t_tool *tool, int start, int end, int position)
{
	if (position == BOTTOM)
		small_b_bottom(tool, start, end);
	if (end == start)
	{
		pa(tool);
		return ;
	}
	else if (end - start == 1)
	{
		two_element_sort(tool, 'b');
		pa(tool);
		pa(tool);
		return ;
	}
	else
		three_element_b_stack(tool, start, end);
	pa(tool);
	pa(tool);
	pa(tool);
}
