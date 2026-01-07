/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:08:38 by arabdull          #+#    #+#             */
/*   Updated: 2026/01/03 19:11:59 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_typed(const char type, va_list args);
int	ft_print_c(char c);
int	ft_print_s(char *s);
int	ft_print_p(void *p);
int	ft_print_p_h(uintptr_t h);
int	ft_print_l(long l);
int	ft_print_u(unsigned int u);
int	ft_print_h(unsigned int u, int is_uppercase);

#endif
