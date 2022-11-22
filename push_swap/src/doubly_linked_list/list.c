/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:29:09 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 13:40:11 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_list(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		message_memory();
	stack->size = 0;
	stack->bottom = NULL;
	stack->top = NULL;
	return (stack);
}

void	delete_list(t_stack *stack)
{
	while (stack->size)
		pop_back(stack);
	free(stack);
	stack = NULL;
}

t_node	*make_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		message_memory();
	node->data = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	push_command(t_commands *stack, char *command)
{
	t_command	*comm;

	comm = make_command(command);
	if (!stack->count)
	{
		stack->top = comm;
		stack->bottom = comm;
	}
	else
	{
		stack->bottom->next = comm;
		comm->prev = stack->bottom;
		stack->bottom = comm;
	}
	stack->count += 1;
}

t_command	*make_command(char *command)
{
	t_command	*comm;

	comm = (t_command *)malloc(sizeof(t_command));
	if (!comm)
		message_memory();
	comm->command = command;
	comm->next = NULL;
	comm->prev = NULL;
	return (comm);
}
