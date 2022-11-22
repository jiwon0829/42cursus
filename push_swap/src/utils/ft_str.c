/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:36:13 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/10/28 16:14:54 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (0);
	while (i < ft_strlen(s1))
	{
		ptr[i] = ((char *)s1)[i];
		++i;
	}
	ptr[i] = 0;
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (0);
		++i;
	}
	if (i == n)
		--i;
	if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		return (1);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst || !src)
		return (ft_strlen(src));
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
