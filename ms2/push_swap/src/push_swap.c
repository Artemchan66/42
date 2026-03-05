/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:35:14 by arabdull          #+#    #+#             */
/*   Updated: 2026/03/05 18:55:42 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int *data;
	int size;
	int capacity;
} t_stack;

char** push_swap(int a[])
{
	char **out = malloc(sizeof(char *) * 4);
	out[0] = "kappaqqqqqqqq";
	out[1] = NULL;
	return out;
}

t_stack *init_stack(int capacity)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if (!stack)
		return NULL;

	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return NULL;
	}
	stack->size = 0;
	stack->capacity = capacity;
	return stack;
}

int	main(int argc, char *argv[])
{
	int n = argc - 1;

	t_stack *stack_a = init_stack(n);
	for (int i = 0; i < n; i++)
	{
		stack_a->data[i] = ft_atoi(argv[i + 1]);
		stack_a->size++;
	}
	t_stack *stack_b = init_stack(n);

	for (int i = 0; i < n; i++)
		printf("%d", stack_a->data[i]);

	free(stack_a->data);
	free(stack_a);
	free(arr);
/*
	char **res = push_swap(a);

	for (int i = 0; res[i] != NULL; i++)
		printf("%s\n", res[i]);
*/
	return 0;
}
