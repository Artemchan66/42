/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numeric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:26:56 by arabdull          #+#    #+#             */
/*   Updated: 2026/01/03 19:48:34 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int u)
{
	int		output;
	char	c;

	output = 0;
	if (u >= 10)
		output += ft_print_u(u / 10);
	c = (u % 10) + '0';
	output += write(1, &c, 1);
	return (output);
}

int	ft_print_h(unsigned int u, int is_uppercase)
{
	int		output;
	char	*base;

	output = 0;
	if (is_uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (u >= 16)
		output += ft_print_h(u / 16, is_uppercase);
	output += write(1, &base[u % 16], 1);
	return (output);
}

int	ft_print_p_h(uintptr_t h)
{
	int		output;
	char	*base;

	output = 0;
	base = "0123456789abcdef";
	if (h >= 16)
		output += ft_print_p_h(h / 16);
	output += write(1, &base[h % 16], 1);
	return (output);
}

int	ft_print_p(void *p)
{
	int			output;
	uintptr_t	addr;

	output = 0;
	if (!p)
	{
		write(1, "(nil)", 5);
		output = output + 5;
		return (output);
	}
	addr = (uintptr_t)p;
	output += write(1, "0x", 2);
	output += ft_print_p_h(addr);
	return (output);
}

int	ft_print_l(long l)
{
	int		output;
	char	c;

	output = 0;
	if (l < 0)
	{
		c = '-';
		output += write(1, &c, 1);
		l = -l;
	}
	if (l >= 10)
	{
		output += ft_print_l(l / 10);
	}
	c = (l % 10) + '0';
	output += write(1, &c, 1);
	return (output);
}
