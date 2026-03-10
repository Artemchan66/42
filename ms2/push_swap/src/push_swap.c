/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:35:14 by arabdull          #+#    #+#             */
/*   Updated: 2026/03/10 17:44:17 by arabdull         ###   ########.fr       */
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

void	pa(t_stack stack, int val)
{

}

//bubble sort
void sort(int arr[], int n)
{
	int	swapped;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int old;
				old = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = old;
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
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

int	get_bit(int val, int bit_index)
{
	return ((val >> bit_index) & 1);
}

int	main(int argc, char *argv[])
{
	int n = argc - 1;

	int *arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		arr[i] = ft_atoi(argv[i + 1]);

	sort(arr, n);

	printf("Sorted input: ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
/*
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
*/
	
	t_stack *stack_a = init_stack(n);
	for (int i = 0; i < n; i++)
	{
		stack_a->data[i] = ft_atoi(argv[i + 1]);
		stack_a->size++;
	}
	t_stack *stack_b = init_stack(n);

	printf("Unsorted input: ");
	for (int i = 0; i < n; i++)
		printf("%d ", stack_a->data[i]);
	printf("\n");

	int *sorted_indexed_arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[j] == stack_a->data[i])
			{
				sorted_indexed_arr[i] = j;
				break;
			}
		}
	}

	printf("Indexed input: ");
	for (int i = 0; i < n; i++)
		printf("%d ", sorted_indexed_arr[i]);
	printf("\n");

	int a = 2;
	int b = a << 1;
	printf("%d\n", b);

	int maxVal = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > maxVal)
			maxVal = arr[i];
	}

	printf("%d\n", maxVal);

	int maxBits = 0;
	while (maxVal > 0)
	{
		maxVal >>= 1;
		maxBits++;
	}

	for (int i = 0; i < maxBits; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (get_bit(arr[j], i))
			{
				
			}
		}
	}

	printf("%d\n", get_bit(2, 1));

	free(stack_a->data);
	free(stack_a);
/*
	char **res = push_swap(a);

	for (int i = 0; res[i] != NULL; i++)
		printf("%s\n", res[i]);
*/
	return 0;
}
