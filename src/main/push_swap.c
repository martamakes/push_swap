/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/18 07:33:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
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

static void    push_swap(t_stack **stack_a, t_stack **stack_b, int total_nodes)
{
    if (is_sorted(*stack_a))
        return ;
    if (total_nodes == 2)
        sa(stack_a);
    else if (total_nodes == 3)
        sort_three(stack_a);
    else if (total_nodes > 3)
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
	  if (DEBUG)
    {
        ft_putstr_fd("Initial state:\n", 1);
        print_stacks(stack_a, stack_b);
    }
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b, total_nodes);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
