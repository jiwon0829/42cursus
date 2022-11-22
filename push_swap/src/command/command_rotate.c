/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:01:48 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:26:25 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_tool *tool)
{
	t_node	*node;

	if (!tool->a->size)
		return ;
	node = make_node(tool->a->top->data);
	pop_front(tool->a);
	push_back(tool->a, node);
	push_command(tool->commands, "ra\n");
}

void	rb(t_tool *tool)
{
	t_node	*node;

	if (!tool->b->size)
		return ;
	node = make_node(tool->b->top->data);
	pop_front(tool->b);
	push_back(tool->b, node);
	push_command(tool->commands, "rb\n");
}

void	rr(t_tool *tool)
{
	t_node	*node;

	if (!tool->a->size)
		return ;
	node = make_node(tool->a->top->data);
	pop_front(tool->a);
	push_back(tool->a, node);
	if (!tool->b->size)
		return ;
	node = make_node(tool->b->top->data);
	pop_front(tool->b);
	push_back(tool->b, node);
	push_command(tool->commands, "rr\n");
}
