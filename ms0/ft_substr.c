/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 07:40:53 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/17 08:24:01 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*ret;

	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ret = sub;
	s += start;
	while (*s && len > 0)
	{
		*sub = *s;
		sub++;
		s++;
		len--;
	}
	*sub = '\0';
	return (ret);
}
