/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:57:40 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/11 13:56:32 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	const char	*p;

	if (*s == c)
		return ((char *)s);
	p = s;
	len = ft_strlen(s);
	s = s + len;
	while (p != s)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}
