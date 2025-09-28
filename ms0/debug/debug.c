#include <stdio.h>
#include <stddef.h>
#include "libft.h"

int main()
{
	printf("isalpha\n");
	char is_alpha_params[6] = {'A', 'Z', 'a', 'z', '0', '!'};
	for (int i = 0; i < 6; i++) {
		printf("\tparam %c, result: %d\n", is_alpha_params[i],
			ft_isalpha(is_alpha_params[i]));
	}

	printf("isdigit\n");
	char is_digit_params[3] = {'0', '9', 'A'};
	for (int i = 0; i < 3; i++) {
		printf("\tparam %c, result: %d\n", is_digit_params[i],
			ft_isdigit(is_digit_params[i]));
	}

	printf("isalnum\n");
	char is_alnum_params[5] = {'0', '9', 'A', 'z', '!'};
	for (int i = 0; i < 5; i++) {
		printf("\tparam %c, result: %d\n", is_alnum_params[i],
			ft_isalnum(is_alnum_params[i]));
	}

	printf("isascii\n");
	unsigned char is_ascii_params[3] = {0x0, 0x7F, 0x80};
	for (int i = 0; i < 3; i++) {
		printf("\thex param %x, result: %d\n", is_ascii_params[i],
			ft_isascii(is_ascii_params[i]));
	}

	printf("isprint\n");
	char is_print_params[3] = {'!', '~', ' '};
	for (int i = 0; i < 3; i++) {
		printf("\tparam %c, result: %d\n", is_print_params[i],
			ft_isprint(is_print_params[i]));
	}

	printf("strlen\n");
	printf("\tparam %s, result: %ld\n", "Yayo", ft_strlen("Yayo"));

	return 0;
}
