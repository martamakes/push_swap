/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:39:36 by marta             #+#    #+#             */
/*   Updated: 2024/10/18 12:51:46 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_parsed_numbers(int *numbers, int count)
{
	int	i;

	if (!numbers || count <= 0)
	{
		printf("No valid numbers parsed.\n");
		return ;
	}
	printf("Parsed numbers: ");
	i = 0;
	while (i < count)
	{
		printf("%d", numbers[i]);
		if (i < count - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}
static void	print_node(t_node *node)
{
	if (node)
		printf("%d", node->value);
	else
		printf("NULL");
}

void	print_stack(t_stack *stack, char stack_name)
{
	t_node	*current;

	if (!stack)
	{
		printf("Stack %c is NULL\n", stack_name);
		return ;
	}
	printf("Stack %c:\n", stack_name);
	printf("  Size: %d\n", stack->size);
	if (!stack)
	{
		ft_printf("Stack %c is NULL\n", stack_name);
		return ;
	}
	printf("Top -> ");
	print_node(stack->top);
	printf("\n");
	current = stack->bottom;
	while (current)
	{
		print_node(current);
		if (current->next)
			printf(" -> ");
		current = current->next;
	}
	printf("\nBottom -> ");
	print_node(stack->bottom);
	printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;

	if (argc < 2)
		return (0);
	numbers = parse_args(&argc, argv);
	if (!numbers || argc == 0)
		return (1);
	if (is_sorted(numbers, argc))
	{
		free(numbers);
		return (0);
	}
	print_parsed_numbers(numbers, argc);
	a = init_a(numbers, argc);
	b = init_b();
	if (a == NULL || b == NULL)
	{
		free(numbers);
		return (1);
	}
	print_stack(a, 'a');
	sort(a, b);
	free(numbers);
	free_stacks(&a, &b);
	return (0);
}
