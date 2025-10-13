/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 07:37:42 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/13 07:58:25 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		unsigned char *val = (unsigned char *)s;
		if (*val == (unsigned char)c)
			return ((void *)s);
		n--;
	}
	return (0);
}
