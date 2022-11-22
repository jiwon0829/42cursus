/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:31:33 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 16:39:11 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*joinandfree(char *str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

char	*read_buffer(int fd, char *str, ssize_t	read_size)
{
	char	*buffer;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(2, 1);
	while (read_size > 0)
	{
		read_size = read(fd, buffer, 1);
		if (read_size == 0)
			break ;
		if (read_size == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = 0;
		str = joinandfree(str, buffer);
		if (!str)
			return (0);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		++i;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*restbuffer(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	rest = ft_calloc(ft_strlen(buffer) - i + 1, 1);
	++i;
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		read_size;

	line = 0;
	read_size = 1;
	buffer = read_buffer(fd, buffer, read_size);
	line = get_line(buffer);
	buffer = restbuffer(buffer);
	free(buffer);
	buffer = 0;
	return (line);
}
