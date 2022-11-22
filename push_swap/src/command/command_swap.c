/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:26:00 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:26:37 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tool *tool)
{
	t_node	*top;
	t_node	*second;

	if (tool->a->size < 2)
		return ;
	top = make_node(tool->a->top->data);
	second = make_node(tool->a->top->next->data);
	pop_front(tool->a);
	pop_front(tool->a);
	push_front(tool->a, top);
	push_front(tool->a, second);
	push_command(tool->commands, "sa\n");
}

void	sb(t_tool *tool)
{
	t_node	*top;
	t_node	*second;

	if (tool->b->size < 2)
		return ;
	top = make_node(tool->b->top->data);
	second = make_node(tool->b->top->next->data);
	pop_front(tool->b);
	pop_front(tool->b);
	push_front(tool->b, top);
	push_front(tool->b, second);
	push_command(tool->commands, "sb\n");
}

void	ss(t_tool *tool)
{
	t_node	*top;
	t_node	*second;

	if (tool->a->size < 2)
		return ;
	top = make_node(tool->a->top->data);
	second = make_node(tool->a->top->next->data);
	pop_front(tool->a);
	pop_front(tool->a);
	push_front(tool->a, top);
	push_front(tool->a, second);
	if (tool->b->size < 2)
		return ;
	top = make_node(tool->b->top->data);
	second = make_node(tool->b->top->next->data);
	pop_front(tool->b);
	pop_front(tool->b);
	push_front(tool->b, top);
	push_front(tool->b, second);
	push_command(tool->commands, "ss\n");
}
