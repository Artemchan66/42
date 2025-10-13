/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 08:21:15 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/13 08:53:53 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *val1 = (const unsigned char *)s1;
	const unsigned char *val2 = (const unsigned char *)s2;

	while (n > 0)
	{
		if (*val1 != *val2)
			return (*val1 - *val2);
		val1++;
		val2++;
		n--;
	}
	return (0);
}
