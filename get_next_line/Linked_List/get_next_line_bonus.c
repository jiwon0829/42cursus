/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:31:33 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/08/11 14:14:15 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_one_line(char *cache)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!cache[i])
		return (NULL);
	while (cache[i] && cache[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
	{
		line[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

t_list	*make_node(int fd)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	node->fd = fd;
	node->cache = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_list	*find_node(t_list **lst, int fd)
{
	t_list	*node;
	t_list	*new;

	if (!*lst)
	{
		*lst = make_node(fd);
		return (*lst);
	}
	node = *lst;
	while (node->next)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (node->fd == fd)
		return (node);
	new = make_node(fd);
	node->next = new;
	new->prev = node;
	return (new);
}

void	del_node(t_list **lst, int fd, int flag)
{
	t_list	*node;

	node = find_node(lst, fd);
	if (flag && node->cache)
		return ;
	free (node->cache);
	if ((*lst)->fd == node->fd)
		*lst = node->next;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free (node);
	node = NULL;
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		del_node(&lst, fd, 0);
	node = find_node(&lst, fd);
	if (!node)
		return (NULL);
	node->cache = read_file(fd, node->cache);
	if (!node->cache)
	{
		del_node(&lst, fd, 1);
		return (NULL);
	}
	line = get_one_line(node->cache);
	node->cache = rest_cache(node->cache);
	del_node(&lst, fd, 1);
	return (line);
}
