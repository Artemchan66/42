/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:35:14 by arabdull          #+#    #+#             */
/*   Updated: 2026/03/12 17:29:53 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int *data;
	int size;
	int capacity;
} t_stack;

void pb(t_stack *a, t_stack *b)
{
	int i;

	if (a->size == 0)
		return;
	i = b->size;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = a->data[0];
	b->size++;
	i = 0;
	while (i < a->size -1 )
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->size--;
	write(1, "pb\n", 3);
}

void pa(t_stack *a, t_stack *b)
{
	int i;

	if (b->size == 0)
		return;
	i = a->size;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = b->data[0];
	a->size++;
	i = 0;
	while (i < b->size -1 )
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->size--;
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	int i;
	int first;

	if (a->size <= 1)
		return;
	first = a->data[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	int i;
	int first;

	if (b->size <= 1)
		return;
	first = b->data[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = first;
	write(1, "rb\n", 3);
}

//bubble sort
void sort(int arr[], int n)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
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

int	is_all_numbers_valid(char *str)
{
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;

	if (!str[i])
		return 0;

	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int n;
	int *arr;
	int i;
	int j = 0;
	int *sorted_indexed_arr;

	n = argc - 1;
	if (n == 0)
		return 1;

	if (!is_all_numbers_valid(argv[]))

	i = 0;
	arr = malloc(sizeof(int) * n);
	while (i < n)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		if (ft_isdigit(arr[i]) == 0)
		{
			printf("Error\n: %d", arr[i]);
			return 1;
		}
		i++;
	}
/*
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[i] == arr[j + 1])
			{
				printf("Error\n");
				return 1;
			}
			j++;
		}
		i++;
	}
*/
	sort(arr, n);

	t_stack *stack_a = init_stack(n);
	t_stack *stack_b = init_stack(n);
	sorted_indexed_arr = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[j] == ft_atoi(argv[i + 1]))
			{
				sorted_indexed_arr[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < n)
	{
		stack_a->data[i] = sorted_indexed_arr[i];
		stack_a->size++;
		i++;
	}

	int max_index = n - 1;
	int maxBits = 0;
	while ((max_index >> maxBits) != 0)
		maxBits++;

	i = 0;
	while (i < maxBits)
	{
		int j = 0;
		while (j < n)
		{
			int num = stack_a->data[0];

			if (((num >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);

			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}

	printf("Result stack_a: \n");
	for (int x = 0; x < n; x++)
		printf("%d ", stack_a->data[x]);

	printf("\n");

	free(stack_a->data);
	free(stack_a);

	return 0;
}
