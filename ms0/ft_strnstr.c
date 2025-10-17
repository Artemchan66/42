/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 06:29:57 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/17 08:19:30 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (big[i] && little[i] && i < len)
	{
		if (big[i] != little[i])
			return (0);
		i++;
	}
	return (little[i] == '\0');
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	while (*big && len >= l_len)
	{
		if (*big == *little && is_match(big, little, len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
