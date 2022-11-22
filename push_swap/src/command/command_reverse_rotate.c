/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:01:43 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:26:22 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_tool *tool)
{
	t_node	*node;

	if (!tool->a->size)
		return ;
	node = make_node(tool->a->bottom->data);
	pop_back(tool->a);
	push_front(tool->a, node);
	push_command(tool->commands, "rra\n");
}

void	rrb(t_tool *tool)
{
	t_node	*node;

	if (!tool->b->size)
		return ;
	node = make_node(tool->b->bottom->data);
	pop_back(tool->b);
	push_front(tool->b, node);
	push_command(tool->commands, "rrb\n");
}

void	rrr(t_tool *tool)
{
	t_node	*node;

	if (!tool->a->size)
		return ;
	node = make_node(tool->a->bottom->data);
	pop_back(tool->a);
	push_front(tool->a, node);
	if (!tool->b->size)
		return ;
	node = make_node(tool->b->bottom->data);
	pop_back(tool->b);
	push_front(tool->b, node);
	push_command(tool->commands, "rrr\n");
}
