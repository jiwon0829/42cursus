/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 07:19:24 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 16:54:01 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hub_command(t_tool *tool, char *command, size_t size)
{
	if (ft_strncmp(command, "sa\n", size))
		sa(tool);
	else if (ft_strncmp(command, "sb\n", size))
		sb(tool);
	else if (ft_strncmp(command, "ss\n", size))
		ss(tool);
	else if (ft_strncmp(command, "ra\n", size))
		ra(tool);
	else if (ft_strncmp(command, "rb\n", size))
		rb(tool);
	else if (ft_strncmp(command, "rr\n", size))
		rr(tool);
	else if (ft_strncmp(command, "rra\n", size))
		rra(tool);
	else if (ft_strncmp(command, "rrb\n", size))
		rrb(tool);
	else if (ft_strncmp(command, "rrr\n", size))
		rrr(tool);
	else if (ft_strncmp(command, "pa\n", size))
		pa(tool);
	else if (ft_strncmp(command, "pb\n", size))
		pb(tool);
	else
		message_not_integer();
}

void	ft_checker(t_tool *tool)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		hub_command(tool, command, ft_strlen(command));
		free(command);
		command = 0;
		command = get_next_line(0);
	}
	if (is_ascending(tool->a, 0, tool->a->size - 1) && !tool->b->size)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_tool	*tool;
	int		i;

	tool = (t_tool *)malloc(sizeof(t_tool));
	if (!tool)
		message_memory();
	init(tool);
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc && argv[i])
		is_valid_argument(argv[i++], tool->a);
	ft_checker(tool);
	if (is_ascending(tool->a, 0, tool->a->size - 1))
		exit(0);
	all_free(tool);
	tool = NULL;
	return (0);
}
