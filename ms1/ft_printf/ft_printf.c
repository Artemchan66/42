#include "ft_printf.h"

int print_u(unsigned int u)
{
	int output = 0;
	char c;

	if (u >= 10)
		output += print_u(u / 10);
	c = (u % 10) + '0';
	output += write(1, &c, 1);
	return output;
}

int print_h(unsigned int u, int is_uppercase)
{
	int output = 0;
	char *base;
	if (is_uppercase)
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	
	if (u >= 16)
		output += print_h(u / 16, is_uppercase);
	output += write(1, &base[u % 16], 1);
	return output;
}

int	print_p_h(uintptr_t h)
{
	int output = 0;
	char *base = "0123456789abcdef";
	
	if (h >= 16)
		output += print_p_h(h / 16);
	output += write(1, &base[h % 16], 1);
	return output;
}

int print_p(void *p)
{
	int output = 0;
	if (!p)
	{
		write(1, "(nil)", 5);
		output = output + 5;
		return output;
	}
	uintptr_t addr;
	addr = (uintptr_t)p;
	output += write(1, "0x", 2);
	output += print_p_h(addr);
	return output;
}

int	print_s(char *s)
{
	int output = 0;

	if (!s)
		return write(1, "(null)", 6);
	while (*s)
	{
		write (1, s, 1);
		s++;
		output++;
	}
	return output;
}

int	print_l(long l)
{
	int 	output = 0;
	char	c;

	if (l < 0)
	{
		c = '-';
		output += write(1, &c, 1);
		l = -l;
	}
	if (l >= 10)
	{
		output += print_l(l / 10);
	}
	c = (l % 10) + '0';
	output += write(1, &c, 1);
	return output;
}

int print_c(char c)
{
	return write(1, &c, 1);
}

int print_typed(const char type, va_list args)
{
	int output;

	output = 0;
	if (type == 'c')
		output += print_c((char)va_arg(args, int));
	else if(type == 's')
		output += print_s(va_arg(args, char *));
	else if (type == 'p')
		output += print_p(va_arg(args, void *));
	else if (type == 'd' || type == 'i')
		output += print_l(va_arg(args, int));
	else if (type == 'u')
		output += print_u(va_arg(args, unsigned int));
	else if (type == 'x')
		output += print_h(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		output += print_h(va_arg(args, unsigned int), 1);
	else
		output += write(1, "%", 1);
	return output;
}

int ft_printf(const char *str, ...)
{
	int output = 0;
	va_list args;

	if (str == NULL)
		return 0;
	va_start(args, str);
	int i;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '%' && str[i+1])
		{
			i++;
			output += print_typed(str[i], args);
			i++;
			continue;
		}
		write(1, &str[i], 1);
		i++;
		output++;
	};
	va_end(args);
	return output;
}
