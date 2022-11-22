/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:56:34 by hanjiwon          #+#    #+#             */
/*   Updated: 2022/10/28 13:49:15 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_sort_number(t_tool *tool)
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = tool->a->top;
	tool->sorted_num = (int *)malloc(sizeof(int) * tool->a->size);
	if (!tool->sorted_num)
		message_memory();
	while (i < tool->a->size)
	{
		tool->sorted_num[i++] = node->data;
		node = node->next;
	}
	bubble_sort(tool);
}

void	bubble_sort(t_tool *tool)
{
	size_t	i;
	size_t	j;
	int		tmp;

	tmp = 0;
	i = 0;
	while (i < tool->a->size)
	{
		j = 0;
		while (j < tool->a->size - 1)
		{
			if (tool->sorted_num[j] > tool->sorted_num[j + 1])
			{
				tmp = tool->sorted_num[j];
				tool->sorted_num[j] = tool->sorted_num[j + 1];
				tool->sorted_num[j + 1] = tmp;
			}
			++j;
		}
		++i;
	}
}
