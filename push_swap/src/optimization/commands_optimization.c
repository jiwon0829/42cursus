/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:56:12 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 14:15:02 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	replace_command(t_commands *commands, size_t position, \
		size_t *size, char *command)
{
	t_command	*first;
	t_command	*second;
	t_command	*comm;
	size_t		i;

	comm = make_command(command);
	i = 0;
	first = commands->top;
	while (i++ < position - *size)
		first = first->next;
	second = first->next;
	if (first->prev)
	{
		comm->prev = first->prev;
		first->prev->next = comm;
	}
	if (second->next)
	{
		comm->next = second->next;
		second->next->prev = comm;
	}
	free_replace_node(first, second);
	++(*size);
}

void	replace_rr(t_tool *tool)
{
	t_command	*comm;
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	comm = tool->commands->top;
	while (i < tool->commands->count - 1)
	{
		if ((ft_strncmp(comm->command, "ra\n", 3) \
		&& ft_strncmp(comm->next->command, "rb\n", 3)) \
		|| (ft_strncmp(comm->command, "rb\n", 3) \
		&& ft_strncmp(comm->next->command, "ra\n", 3)))
		{
			comm = comm->next->next;
			replace_command(tool->commands, i, &size, "rr\n");
			++i;
		}
		else
			comm = comm->next;
		++i;
	}
	tool->commands->count -= size;
}

void	replace_rrr(t_tool *tool)
{
	t_command	*comm;
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	comm = tool->commands->top;
	while (i < tool->commands->count - 1)
	{
		if ((ft_strncmp(comm->command, "rra\n", 4) \
		&& ft_strncmp(comm->next->command, "rrb\n", 4)) \
		|| (ft_strncmp(comm->command, "rrb\n", 4) \
		&& ft_strncmp(comm->next->command, "rra\n", 4)))
		{
			comm = comm->next->next;
			replace_command(tool->commands, i, &size, "rrr\n");
			++i;
		}
		else
			comm = comm->next;
		++i;
	}
	tool->commands->count -= size;
}

void	replace_ss(t_tool *tool)
{
	t_command	*comm;
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	comm = tool->commands->top;
	while (i < tool->commands->count - 1)
	{
		if ((ft_strncmp(comm->command, "sa\n", 3) \
		&& ft_strncmp(comm->next->command, "sb\n", 3)) \
		|| (ft_strncmp(comm->command, "sb\n", 3) \
		&& ft_strncmp(comm->next->command, "sa\n", 3)))
		{
			comm = comm->next->next;
			replace_command(tool->commands, i, &size, "ss\n");
			++i;
		}
		else
			comm = comm->next;
		++i;
	}
	tool->commands->count -= size;
}

void	command_optimization(t_tool *tool)
{
	replace_rr(tool);
	replace_rrr(tool);
	replace_ss(tool);
}
