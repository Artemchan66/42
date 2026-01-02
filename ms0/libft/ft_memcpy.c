/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:11:42 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/01 19:45:19 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
