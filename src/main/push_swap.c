/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 18:02:48 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Main sorting function that chooses the appropriate algorithm
** based on the size of the stack
*/
void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sa(a, true);
	else if (size == 3)
		sort_three(a);
	else if (size < 10)
		sort_small(a, b, size);
	else
	{
		index_stack(*a);
		turkish_sort(a, b);
	}
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	sort_stack(stack_a, stack_b);
}

static void	get_numbers(char *av, t_stack **stack_a)
{
	char	**numbers;
	long	num;
	int		i;

	numbers = ft_split(av, ' ');
	if (!numbers)
		error_exit(stack_a, NULL);
	i = 0;
	while (numbers[i])
	{
		if (!is_valid_input(numbers[i]))
		{
			ft_split_free(numbers);
			error_exit(stack_a, NULL);
		}
		num = ft_atoll(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_split_free(numbers);
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
	if (VISUALS)
	{
		print_debug_str("Initial state:\n");
		print_stacks(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
