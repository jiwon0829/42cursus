/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:25:20 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 14:20:19 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_overlap(t_stack *stack, int value)
{
	t_node	*index;
	t_node	*node;

	if (stack->size)
	{
		index = stack->top;
		while (index->next)
		{
			if (index->data == value)
				message_overlap();
			index = index->next;
		}
		if (index->data == value)
			message_overlap();
	}
	node = make_node(value);
	push_back(stack, node);
}

void	is_valid_argument(char *argument, t_stack *a_stack)
{
	int		value;
	char	**multiple_values;
	size_t	word_cnt;
	size_t	i;

	if (ft_strchr(argument, ' '))
	{
		multiple_values = ft_split(argument, ' ');
		word_cnt = split_cnt(argument, ' ');
		if (!word_cnt)
			message_not_integer();
		i = 0;
		while (i < word_cnt)
		{
			value = ft_atoi(multiple_values[i++]);
			check_overlap(a_stack, value);
		}
		multiple_values = split_free(&multiple_values, word_cnt);
	}
	else
	{
		value = ft_atoi(argument);
		check_overlap(a_stack, value);
	}
}

int	is_ascending(t_stack *stack, size_t start, size_t end)
{
	t_node	*node;
	size_t	i;

	i = 0;
	node = stack->top;
	while (i < end - start)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
		++i;
	}
	return (1);
}

int	is_descending(t_stack *stack, size_t start, size_t end)
{
	t_node	*node;
	size_t	i;

	i = 0;
	node = stack->top;
	while (i < end - start)
	{
		if (node->data < node->next->data)
			return (0);
		node = node->next;
		++i;
	}
	return (1);
}
