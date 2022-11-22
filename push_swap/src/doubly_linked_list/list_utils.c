/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:07:54 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:41:43 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_front(t_stack *stack)
{
	t_node	*node;

	if (!stack->size)
		return ;
	else if (stack->size == 1)
	{
		node = stack->top;
		stack->bottom = NULL;
		stack->top = NULL;
	}
	else
	{
		node = stack->top;
		node->next->prev = NULL;
		stack->top = node->next;
	}
	free(node);
	node = NULL;
	stack->size -= 1;
}

void	pop_back(t_stack *stack)
{
	t_node	*node;

	if (!stack->size)
		return ;
	else if (stack->size == 1)
	{
		node = stack->bottom;
		stack->bottom = NULL;
		stack->top = NULL;
	}
	else
	{
		node = stack->bottom;
		node->prev->next = NULL;
		stack->bottom = node->prev;
	}
	free(node);
	node = NULL;
	stack->size -= 1;
}

void	push_front(t_stack *stack, t_node *node)
{
	t_node	*top;

	if (!stack->size)
	{
		stack->bottom = node;
		stack->top = node;
	}
	else
	{
		top = stack->top;
		top->prev = node;
		node->prev = NULL;
		node->next = top;
		stack->top = node;
	}
	stack->size += 1;
}

void	push_back(t_stack *stack, t_node *node)
{
	t_node	*bottom;

	if (!stack->size)
	{
		stack->bottom = node;
		stack->top = node;
	}
	else
	{
		bottom = stack->bottom;
		bottom->next = node;
		node->prev = bottom;
		node->next = NULL;
		stack->bottom = node;
	}
	stack->size += 1;
}
