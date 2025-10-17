/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:22:36 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/17 08:22:15 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_b;
	unsigned char const	*src_b;

	if (!dest && !src)
		return (NULL);
	dest_b = dest;
	src_b = src;
	if (dest_b < src_b)
	{
		while (n--)
		{
			*dest_b++ = *src_b++;
		}
	}
	else if (dest_b > src_b)
	{
		dest_b += n;
		src_b += n;
		while (n--)
		{
			*--dest_b = *--src_b;
		}
	}
	return (dest);
}
