/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:04:00 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 14:08:56 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_top_a(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;
	int	i;
	int	tmp;

	if (end - start < 3)
		return (hub_small_a_stack_size(tool, start, end, TOP));
	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	i = 0;
	while (i++ <= end - start)
	{
		tmp = tool->a->top->data;
		if (tmp >= tool->sorted_num[big_pivot])
			ra(tool);
		else
		{
			pb(tool);
			if (tmp < tool->sorted_num[small_pivot])
				rb(tool);
		}
	}
	return (recur_top_a(tool, start, end));
}

void	sort_bottom_a(t_tool *tool, int start, int end)
{
	int	i;
	int	tmp;

	if ((int)tool->a->size == end - start + 1)
	{
		sort_top_a(tool, start, end);
		return ;
	}
	if (end - start < 3)
		return (hub_small_a_stack_size(tool, start, end, BOTTOM));
	i = 0;
	while (i++ <= end - start)
	{
		tmp = tool->a->bottom->data;
		rra(tool);
		if (tmp < tool->sorted_num[find_pivot(start, end, BIG)])
		{
			pb(tool);
			if (tmp < tool->sorted_num[find_pivot(start, end, SMALL)])
				rb(tool);
		}
	}
	return (recur_bottom_a(tool, start, end));
}

void	recur_top_a(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;

	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	sort_bottom_a(tool, big_pivot, end);
	sort_top_b(tool, small_pivot, big_pivot - 1);
	sort_bottom_b(tool, start, small_pivot - 1);
}

void	recur_bottom_a(t_tool *tool, int start, int end)
{
	int	small_pivot;
	int	big_pivot;

	small_pivot = find_pivot(start, end, SMALL);
	big_pivot = find_pivot(start, end, BIG);
	sort_top_a(tool, big_pivot, end);
	sort_top_b(tool, small_pivot, big_pivot - 1);
	sort_bottom_b(tool, start, small_pivot - 1);
}

void	hub_small_a_stack_size(t_tool *tool, int start, int end, int position)
{
	int	i;

	if (position == BOTTOM)
	{
		i = 0;
		while (i++ <= end - start)
			rra(tool);
		if (i == 1 && tool->a->top->data > tool->a->top->next->data)
			sa(tool);
	}
	if (end - start == 0)
		return ;
	else if (end - start < 2)
		two_element_sort(tool, 'a');
	else if (tool->a->size < 4)
		only_three_element_a_stack(tool, start, end);
	else
		three_element_a_stack(tool, start, end);
}
