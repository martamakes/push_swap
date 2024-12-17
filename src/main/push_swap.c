/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 11:36:15 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int total_nodes)
{
	if (total_nodes == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (total_nodes == 3)
		sort_three(stack_a);
	else if (total_nodes > 3 && !is_sorted(*stack_a))
		sort_stack(stack_a, stack_b);
}

static void	get_numbers(char *av, t_stack **stack_a)
{
	char		**numbers;
	long		num;
	int			i;

	numbers = ft_split(av, ' ');
	if (!numbers)
		error_exit(stack_a, NULL);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_input(numbers[i]))
		{
			free_split(numbers);
			error_exit(stack_a, NULL);
		}
		num = ft_atoll(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free_split(numbers);
			error_exit(stack_a, NULL);
		}
		stack_add_back(stack_a, stack_new((int)num));
		free(numbers[i++]);
	}
	free(numbers);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		total_nodes;
	int		i;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < ac)
		get_numbers(av[i++], &stack_a);
	if (!stack_a || check_duplicates(stack_a))
		error_exit(&stack_a, NULL);
	total_nodes = stack_size(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b, total_nodes);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
