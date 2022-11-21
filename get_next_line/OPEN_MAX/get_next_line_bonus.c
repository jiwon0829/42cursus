/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:31:33 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/08/10 18:34:25 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*joinAndFree(char *str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(str, buffer);
	free(str);
	return (tmp);
}

char	*read_buffer(int fd, char *str)
{
	char	*buffer;
	ssize_t	read_size;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	read_size = 1;
	while (read_size != 0 && !ft_strchr(str, '\n'))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			/*if (str)
				free(str);*/
			free(buffer);
			return (NULL);
		}
		buffer[read_size] = 0;
		str = joinAndFree(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*getLine(char *buffer)
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

char	*restBuffer(char *buffer)
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
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free (buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = getLine(buffer[fd]);
	buffer[fd] = restBuffer(buffer[fd]);
	return (line);
}
