/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:31:30 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/08/10 15:55:47 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + i));
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}

char	*ft_strjoin(char *cache, char *buffer)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(ft_strlen(cache) + ft_strlen(buffer) + 1);
	if (!res)
	{
		if (cache)
			free(cache);
		return (NULL);
	}
	i = 0;
	while (cache && cache[i])
	{
		res[i] = cache[i];
		i++;
	}
	j = 0;
	while (buffer[j])
		res[i++] = buffer[j++];
	res[i] = '\0';
	if (cache)
		free(cache);
	return (res);
}

char	*rest_cache(char *cache)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	if (!cache[i] || !cache[i + 1])
	{
		free (cache);
		return (NULL);
	}
	res = malloc(ft_strlen(cache) - i + 1);
	if (!res)
	{
		free (cache);
		return (NULL);
	}
	i++;
	j = 0;
	while (cache[i])
		res[j++] = cache[i++];
	res[j] = '\0';
	free (cache);
	return (res);
}

char	*read_file(int fd, char *cache)
{
	char	*buffer;
	ssize_t	byte_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read != 0 && !ft_strrchr(cache, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			if (cache)
				free (cache);
			free (buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		cache = ft_strjoin(cache, buffer);
	}
	free (buffer);
	return (cache);
}
