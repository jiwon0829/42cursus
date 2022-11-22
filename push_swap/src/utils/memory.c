/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:19:24 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 14:14:56 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_commands	*create_commands(void)
{
	t_commands	*comm;

	comm = (t_commands *)malloc(sizeof(t_commands));
	if (!comm)
		message_memory();
	comm->count = 0;
	comm->top = NULL;
	comm->bottom = NULL;
	return (comm);
}

void	init(t_tool *tool)
{
	t_stack		*a;
	t_stack		*b;
	t_commands	*commands;

	a = create_list();
	b = create_list();
	commands = create_commands();
	tool->a = a;
	tool->b = b;
	tool->commands = commands;
	tool->sorted_num = 0;
	return ;
}

void	all_free(t_tool *tool)
{
	delete_list(tool->a);
	delete_list(tool->b);
	delete_commands(tool->commands);
	free(tool->sorted_num);
	free(tool);
	tool = NULL;
	return ;
}

void	delete_commands(t_commands *stack)
{
	t_command	*comm;

	while (stack->count)
	{
		comm = stack->bottom;
		if (stack->count == 1)
		{
			stack->bottom = NULL;
			stack->top = NULL;
		}
		else
		{
			comm->prev->next = NULL;
			stack->bottom = comm->prev;
		}
		free(comm);
		comm = NULL;
		stack->count -= 1;
	}
	free(stack);
	stack = NULL;
}

void	free_replace_node(t_command *first, t_command *second)
{
	free(first);
	first = NULL;
	free(second);
	second = NULL;
}
