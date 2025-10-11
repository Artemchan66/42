/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:22:36 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/08 18:36:12 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overlap(unsigned char *dest,
unsigned char const *src, size_t n)
{
	unsigned char const	*src_o;

	src_o = src;
	while (n > 0)
	{
		if (dest == src_o)
		{
			return (1);
		}
		src_o++;
		n--;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_b;
	unsigned char const	*src_b;

	dest_b = dest;
	src_b = src;
	if (check_overlap(dest_b, src_b, n) == 1)
	{
		dest_b = dest_b + n - 1;
		src_b = src_b + n - 1;
	}
	while (n > 0)
	{
		*dest_b = *src_b;
		dest_b--;
		src_b--;
		n--;
	}
	return (dest);
}
