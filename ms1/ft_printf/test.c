#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h> //for storing a large enough hex pointer value

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

int ft_printf(const char *format, ...)
{
	char *output;
	va_list args;

	if (format == NULL)
		return 0;

	va_start(args, format);
	int i;
	i = 0;
	while(format[i] != '\0')
	{
		if (format[i] == '%' && format[i+1])
		{
			i++;
			if (format[i] == 'c')
			{
				char a = (char)va_arg(args, int);
				write(1, &a , 1);
				i++;
				continue;
			}
			if (format[i] == 's')
			{
				char *b = va_arg(args, char *);
				while(*b)
				{
					write(1, b, 1);
					b++;
				}
				i++;
				continue;
			}
			if (format[i] == 'p')
			{
				char *base = "0123456789abcdef";
				void *c = va_arg(args, void *);
				if (!c)
				{
					write(1, "0x0", 3);
					continue;
				}
				uintptr_t addr;

				addr = (uintptr_t)c;

				write(1, "0x", 2);
			}
		}
		write(1, &format[i], 1);
		i++;
	};
}

int main()
{


	//ft_printf("%c", 'a');

	//write(1, a, 1);
	return 0;
}
