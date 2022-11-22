/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:26:00 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:26:14 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_tool *tool)
{
	t_node	*node;

	if (!tool->b->size)
		return ;
	node = make_node(tool->b->top->data);
	pop_front(tool->b);
	push_front(tool->a, node);
	push_command(tool->commands, "pa\n");
}

void	pb(t_tool *tool)
{
	t_node	*node;

	if (!tool->a->size)
		return ;
	node = make_node(tool->a->top->data);
	pop_front(tool->a);
	push_front(tool->b, node);
	push_command(tool->commands, "pb\n");
}
