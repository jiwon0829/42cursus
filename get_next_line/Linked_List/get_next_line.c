/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:31:33 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/08/10 16:02:05 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cache = read_file(fd, cache);
	if (!cache)
		return (NULL);
	line = get_one_line(cache);
	cache = rest_cache(cache);
	return (line);
}
