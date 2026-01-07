/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 19:45:12 by arabdull          #+#    #+#             */
/*   Updated: 2026/01/03 20:46:11 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	output;

	output = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write (1, s, 1);
		s++;
		output++;
	}
	return (output);
}

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_typed(const char type, va_list args)
{
	int	output;

	output = 0;
	if (type == 'c')
		output += ft_print_c((char)va_arg(args, int));
	else if (type == 's')
		output += ft_print_s(va_arg(args, char *));
	else if (type == 'p')
		output += ft_print_p(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		output += ft_print_l(va_arg(args, int));
	else if (type == 'u')
		output += ft_print_u(va_arg(args, unsigned int));
	else if (type == 'x')
		output += ft_print_h(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		output += ft_print_h(va_arg(args, unsigned int), 1);
	else if (type == 'q')
	{
		output += write(1, "42", 2);
	}
	else
		output += write(1, "%", 1);
	return (output);
}

int	ft_printf(const char *str, ...)
{
	int		output;
	va_list	args;
	int		i;

	output = 0;
	if (str == NULL)
		return (output);
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			output += ft_print_typed(str[i], args);
			i++;
			continue ;
		}
		write(1, &str[i], 1);
		i++;
		output++;
	}
	va_end(args);
	return (output);
}
