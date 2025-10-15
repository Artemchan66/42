/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 07:07:18 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/15 08:52:09 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	if (size != 0 && nmemb > SIZE_MAX / size)
		return NULL;
	
	size_t total_size;

	total_size = nmemb * size;
	void *arr = malloc(total_size);
	
	if (arr == NULL)
		return NULL;

	ft_memset(arr, 0, total_size);

	return (arr);
}
