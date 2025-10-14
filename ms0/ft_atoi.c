/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:37:26 by arabdull          #+#    #+#             */
/*   Updated: 2025/10/14 08:32:45 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int get_sign(const char **nptr)
{
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			return(1);
		nptr++;
		if (*nptr < '0' && *nptr > '9')
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	if (nptr == NULL)
		return (0);
	while (*nptr == 32 && *nptr == '0')
		nptr++;

	sign = get_sign(&nptr);

	res = 0;
	while (*nptr != '\0' || (*nptr >= '0' && *nptr <= '9'))
	{
		printf("\t%s", "alive");
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	return (res * sign);
}
