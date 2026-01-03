#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a = 42;
	int out = 0;
	out = printf("%p\n", &a);
	printf("%d\n", out);

	out = 0;
	out = ft_printf("%p\n", &a);
	printf("%d\n", out);
	return 0;
}

