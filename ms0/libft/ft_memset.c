/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:14:00 by arabdull          #+#    #+#             */
/*   Updated: 2025/09/29 18:46:44 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;

	b = s;
	while (n > 0)
	{
		*b = (unsigned char)c;
		n--;
		b++;
	}
	return (s);
}
