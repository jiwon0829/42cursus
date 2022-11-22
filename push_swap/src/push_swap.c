/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:28:39 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 16:43:23 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_tool	*tool;
	int		i;

	tool = (t_tool *)malloc(sizeof(t_tool));
	if (!tool)
		message_memory();
	init(tool);
	if (argc < 2)
		exit (0);
	i = 1;
	while (i < argc && argv[i])
		is_valid_argument(argv[i++], tool->a);
	if (is_ascending(tool->a, 0, tool->a->size - 1))
		exit (0);
	quick_sort(tool);
	command_optimization(tool);
	show_commands(tool->commands);
	all_free(tool);
	tool = NULL;
	return (0);
}

void	show_commands(t_commands *commands)
{
	t_command	*comm;
	size_t		i;
	size_t		len;

	i = 0;
	if (!commands->count)
		return ;
	comm = commands->top;
	while (i < commands->count)
	{
		len = ft_strlen(comm->command);
		write(1, comm->command, len);
		comm = comm->next;
		++i;
	}
}
