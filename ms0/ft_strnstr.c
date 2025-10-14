/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 06:29:57 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/14 07:35:26 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	l_len;
	int	match_len;

	if (*little == '\0')
		return ((char *)big);
	l_len = ft_strlen(little);
	match_len = 0;
	while (len > 0 && *big != '\0')
	{
		if (*big == *little)
		{
			match_len++;
			little++;
		}
		else
		{
			little -= match_len;
			match_len = 0;
		}
		big++;
		len--;
	}
	if (l_len == match_len)
		return ((char *)big - l_len);
	return (NULL);
}
