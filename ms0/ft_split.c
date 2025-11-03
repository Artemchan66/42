/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:11:41 by arabdull          #+#    #+#             */
/*   Updated: 2025/11/03 16:32:21 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	res;

	res = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res++;
			while (*s && !(*s == c))
				s++;
		}
	}
	return (res);
}

static char	*alloc_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = 0;
	while (s[len] && !(s[len] == c))
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

static void	free_all(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**res;

	i = 0;
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res[i] = alloc_word(s, c);
			if (!res[i])
				return (free_all(res, i - 1), NULL);
			i++;
			while (*s && !(*s == c))
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
