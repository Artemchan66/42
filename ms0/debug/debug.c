#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "libft.h"

void t_calloc()
{
	printf("%s\n", __func__);
	ft_calloc(1, 4);
	/*
	char p1[8][10] = { " \t\n\v\f\r123", "-123", "123asd",
		"--123", "", "asd", "+", "-"};
	int des_res[8] = {123, -123, 123,
		0, 0, 0, 0, 0};
	
	for (int i = 0; i < sizeof(p1)/sizeof(p1[0]); i++)
	{
		int res = ft_atoi(p1[i]);

		printf(
			"\tparams: %s\n"
			"\tdesired res: %d\n"
			"\tactual res: %d\n\n",
			p1[i],
			des_res[i],
			res
		);
	}
	*/
}

void t_atoi()
{
	printf("%s\n", __func__);
	char p1[8][10] = { " \t\n\v\f\r123", "-123", "123asd",
		"--123", "", "asd", "+", "-"};
	int des_res[8] = {123, -123, 123,
		0, 0, 0, 0, 0};
	
	for (int i = 0; i < sizeof(p1)/sizeof(p1[0]); i++)
	{
		int res = ft_atoi(p1[i]);

		printf(
			"\tparams: %s\n"
			"\tdesired res: %d\n"
			"\tactual res: %d\n\n",
			p1[i],
			des_res[i],
			res
		);
	}
}

void t_strnstr()
{
	printf("%s\n", __func__);
	printf("\t%s", ft_strnstr("ssaAss", "Ass", 6));
	char p1[4][7] = { "ssaAss", "ssaAss", "ssaAss", "ssaAss"};
	char p2[4][7] = { "Ass", "sas", "Ass", ""};
	size_t p3[4] = {6, 6, 3, 6};
	int offsets[4] = {3, 7, 7, 0};

	for (int i = 0; i < sizeof(p1)/sizeof(p1[0]); i++)
	{
		char *res = ft_strnstr(p1[i], p2[i], p3[i]);
		char *des_res = &p1[i][offsets[i]];

		printf(
			"\tparams: %s, %s, %lu\n",
			p1[i], p2[i], p3[i]
		);
		if (res)
		{
			printf(
				"\tdesired res: %c -> %p\n"
				"\tactual res: %c -> %p\n\n",
				*des_res, (void *)des_res,
				*res, (void *)res
			);
		}
		else
		{
			printf(
				"\tdesired res: %p\n"
				"\tactual res: %p\n\n",
				(void *)0,
				(void *)res
			);
		}
	}
}

void t_memcmp()
{
	printf("%s\n", __func__);
	char p1[3][4] = { "Ass", "aSs", "ass"};
	char p2[3][4] = { "Ass", "ass", "aSs"};
	size_t p3[3] = {3, 3, 3};
	int des_res[3] = {0, -32, 32};

	for (int i = 0; i < sizeof(p1)/sizeof(p1[0]); i++)
	{
		int res = ft_memcmp(p1[i], p2[i], p3[i]);

		printf(
			"\tparams: %s, %s, %lu\n"
			"\tdesired res: %d\n"
			"\tactual res: %d\n\n",
			p1[i], p2[i], p3[i],
			des_res[i],
			res
		);
	}
}

void t_memchr()
{
	printf("%s\n", __func__);
	char p1[3][4] = { "Ass", "ass", "ssA"};
	int p2[3] = {65, 65, 65};
	size_t p3[3] = {3, 3, 2};
	int offsets[3] = {0, 4, 4};

	for (int i = 0; i < sizeof(p1)/sizeof(p1[0]); i++)
	{
		char *res = ft_memchr(p1[i], p2[i], p3[i]);
		char *des_res = &p1[i][offsets[i]];

		printf(
			"\tparams: %s, %d(%c), %lu\n",
			p1[i], p2[i],(char)p2[i], p3[i]
		);
		if (res)
		{
			printf(
				"\tdesired res: %c -> %p\n"
				"\tactual res: %c -> %p\n\n",
				*des_res, (void *)des_res,
				*res, (void *)res
			);
		}
		else
		{
			printf(
				"\tdesired res: %p\n"
				"\tactual res: %p\n\n",
				(void *)0,
				(void *)res
			);
		}
	}
}

void t_strncmp()
{
	printf("%s\n", __func__);
	char p1[4][4] = { "ass", "aSs", "ass", "asS"};
	char p2[4][4] = { "ass", "ass", "aSs", "ass" };
	int p3[4] = {3, 3, 3, 2};
	int des_res[4] = {0, -32, 32, 0};
	int res;
	
	for (int i = 0; i < sizeof(p1)/sizeof(p1[0]); i++)
	{
		res = ft_strncmp(p1[i], p2[i], p3[i]);

		printf(
			"\tparams: %s, %s, %d\n"
			"\tdesired res: %d\n"
			"\tactual res: %d\n\n",
			p1[i], p2[i], p3[i],
			des_res[i],
			res
		);
	}
}

void t_strlcat()
{
	printf("%s\n", __func__);
	char p1[5];
	char p2[9] = "bajojajo";
	size_t res = ft_strlcat(p1, p2, sizeof(p1));

	printf(
		"\tparams: %lu(empty dest buff size), %s\n"
		"\tdest value: %s\n"
		"\tdesired res: %lu\n"
		"\tactual res: %lu\n",
		sizeof(p1), p2,
		p1,
		strlen(p1) + strlen(p2),
		res
	);
}

void t_strlcpy()
{
	printf("%s\n", __func__);
	char p1[5];
	char p2[9] = "bajojajo";
	size_t res = ft_strlcpy(p1, p2, sizeof(p1));

	printf(
		"\tparams: %lu(empty dest buff size), %s\n"
		"\tdest value: %s\n"
		"\tdesired res: %lu\n"
		"\tactual res: %lu\n",
		sizeof(p1), p2,
		p1,
		strlen(p2),
		res
	);
}

void t_strchr()
{
	printf("ft_strchr\n");
	char p1[2][6] = {"Aboba", "Aboba"};
	int p2[2] = {65, 0};
	int offsets[2] = {0, 5};
	for (int i = 0; i < 2; i++) {

		char *res = ft_strchr(p1[i], p2[i]);
		char *expected_res = &p1[i][offsets[i]];

		printf(
			"\tparams: %s, %d(%c)\n"
			"\tdesired res %c -> %p\n"
			"\tactual res: %c -> %p\n\n",
			p1[i], p2[i], (char )p2[i],
			*expected_res, (void *)expected_res,
			*res, (void *)res
		);
	}
}

void t_strrchr()
{
	printf("ft_strrchr\n");
	char p1[2][6] = {"Aboba", "Aboba"};
	int p2[2] = {98, 0};
	int offsets[2] = {3, 5};
	for (int i = 0; i < 2; i++) {

		char *res = ft_strrchr(p1[i], p2[i]);
		char *expected_res = &p1[i][offsets[i]];

		printf(
			"\tparams: %s, %d(%c)\n"
			"\tdesired res %c -> %p\n"
			"\tactual res: %c -> %p\n\n",
			p1[i], p2[i], (char )p2[i],
			*expected_res, (void *)expected_res,
			*res, (void *)res
		);
	}
}

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
	
	printf("ft_memcpy\n");
	char memcpy_param[20] = "Hello, World!";
	ft_memcpy(memcpy_param + 2, memcpy_param, 10);
	printf("\tparams %s, %s, %d result: %s\n", "llo, World!", "Hello, World!", 10, memcpy_param);

	printf("ft_memmove\n");
	char memmove_param[20] = "Hello, World!";
	ft_memmove(memmove_param + 2, memmove_param, 10);
	printf("\tparams %s, %s, %d result: %s\n", "llo, World!", "Hello, World!", 10, memmove_param);

	printf("ft_toupper\n");
	char t_up_p[2] = {'a', 'Z'};
	for (int i = 0; i < 2; i++) {
		printf("\tparam %c, result: %c\n", t_up_p[i],
			ft_toupper(t_up_p[i]));
	}

	printf("ft_tolower\n");
	char t_lo_p[2] = {'a', 'Z'};
	for (int i = 0; i < 2; i++) {
		printf("\tparam %c, result: %c\n", t_lo_p[i],
			ft_tolower(t_lo_p[i]));
	}

	t_strchr();
	t_strrchr();
	t_strlcpy();
	t_strlcat();
	t_strncmp();
	t_memchr();
	t_memcmp();
	t_strnstr();
	t_atoi();
	t_calloc();

	return 0;
}
