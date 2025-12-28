/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:35:59 by arabdull          #+#    #+#             */
/*   Updated: 2025/12/28 12:05:12 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_b;
	const unsigned char	*src_b;

	dest_b = dest;
	src_b = src;
	while (n > 0)
	{
		*dest_b = *src_b;
		dest_b++;
		src_b++;
		n--;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	char	*ret;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	ret = dup;
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}
