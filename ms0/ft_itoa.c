/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:44:39 by arabdull          #+#    #+#             */
/*   Updated: 2025/11/03 13:56:56 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	buff;
	char	*res;

	len = get_len(n);
	buff = n;
	res = (char *)malloc((len + 1) * sizeof(char));
	res[len] = '\0';
	if (buff < 0)
		buff = -buff;
	if (buff == 0)
		res[0] = '0';
	while (buff > 0)
	{
		res[--len] = (buff % 10) + '0';
		buff /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
