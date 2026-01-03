/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:08:38 by arabdull          #+#    #+#             */
/*   Updated: 2026/01/03 18:35:11 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_typed(const char type, va_list args);
int	print_c(char c);
int	print_s(char *s);
int	print_p(void *p);
int	print_p_h(uintptr_t h);
int	print_l(long l);
int	print_u(unsigned int u);
int print_h(unsigned int u, int is_uppercase);

#endif
