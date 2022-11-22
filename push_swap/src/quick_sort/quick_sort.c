/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:52:22 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 14:04:08 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_b_bottom(t_tool *tool, int start, int end)
{
	int	i;

	i = 0;
	while (i++ <= end - start)
		rrb(tool);
	if (i == 1 && tool->b->top->data > tool->b->top->next->data)
		sb(tool);
}

int	find_pivot(int start, int end, int type)
{
	int	small_pivot;
	int	big_pivot;

	if (end - start == 0)
		return (start);
	if (end - start < 2)
		return (start + 1);
	small_pivot = start + ((end - start) + 1) / 3;
	big_pivot = ((end - small_pivot) / 2) + small_pivot;
	if (type == SMALL)
		return (small_pivot);
	else if (type == BIG)
		return (big_pivot);
	return (0);
}

void	quick_sort(t_tool *tool)
{
	size_t	size;

	push_sort_number(tool);
	size = tool->a->size;
	if (size < 3)
		two_element_sort(tool, 'a');
	else if (size == 5)
		five_element_sort(tool);
	else
		sort_top_a(tool, 0, tool->a->size - 1);
}
