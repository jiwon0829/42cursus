/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_optimization.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 22:00:56 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 13:31:02 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element_sort(t_tool *tool, char target)
{
	t_stack	*stack;

	if (target == 'a')
	{
		stack = tool->a;
		if (is_ascending(stack, 0, stack->size - 1))
			return ;
		if (stack->top->data > stack->top->next->data)
			sa(tool);
	}
	else if (target == 'b')
	{
		stack = tool->b;
		if (is_descending(stack, 0, stack->size - 1))
			return ;
		if (stack->top->data < stack->top->next->data)
			sb(tool);
	}
}

void	only_three_element_a_stack(t_tool *tool, int start, int end)
{
	int	pivot;

	pivot = end - 1;
	if (is_ascending(tool->a, start, end))
		return ;
	if (tool->a->top->data > tool->sorted_num[pivot])
		ra(tool);
	if (tool->a->top->next->data > tool->sorted_num[pivot])
		rra(tool);
	if (tool->a->top->data > tool->sorted_num[pivot - 1])
		sa(tool);
}

void	only_three_element_b_stack(t_tool *tool, int start, int end)
{
	int	pivot;

	pivot = start + 1;
	if (is_descending(tool->b, start, end))
		return ;
	if (tool->b->top->next->data == tool->sorted_num[pivot - 1])
		rrb(tool);
	else if (tool->b->top->data == tool->sorted_num[pivot - 1])
		rb(tool);
	if (tool->b->top->data < tool->b->top->next->data)
		sb(tool);
}

void	three_element_a_stack(t_tool *tool, int start, int end)
{
	int	pivot;

	pivot = find_pivot(start, end, SMALL);
	if (is_ascending(tool->a, 0, 2))
		return ;
	if (tool->a->top->next->next->data == tool->sorted_num[pivot + 1])
	{
		sa(tool);
		return ;
	}
	if (tool->a->top->data == tool->sorted_num[pivot + 1])
		sa(tool);
	pb(tool);
	sa(tool);
	pa(tool);
	if (is_ascending(tool->a, 0, 2))
		return ;
	sa(tool);
}

void	three_element_b_stack(t_tool *tool, int start, int end)
{
	int	pivot;

	pivot = find_pivot(start, end, SMALL);
	if (is_descending(tool->b, 0, 2))
		return ;
	if (tool->b->top->next->next->data == tool->sorted_num[pivot - 1])
	{
		sb(tool);
		return ;
	}
	if (tool->b->top->data == tool->sorted_num[pivot - 1])
		sb(tool);
	pa(tool);
	sb(tool);
	pb(tool);
	if (is_descending(tool->b, 0, 2))
		return ;
	sb(tool);
}
