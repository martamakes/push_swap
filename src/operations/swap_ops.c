/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:09:17 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 17:08:04 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the first two elements of a stack.
** Does nothing if there are less than 2 elements.
*/
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/*
** sa (swap a): Swaps the top two elements of stack a.
** Does nothing if there's one or no elements.
*/
void	sa(t_stack **stack_a)
{
	swap(stack_a);
    ft_putstr_fd("sa\n", 1);
	if (VISUALS)
	{
		print_debug_str("After sa:\n");
		print_one(*stack_a, 'A');
	}
}

/*
** sb (swap b): Swaps the top two elements of stack b.
** Does nothing if there's one or no elements.
*/
void	sb(t_stack **stack_b)
{
	swap(stack_b);
    ft_putstr_fd("sb\n", 1);
	if (VISUALS)
	{
		print_debug_str("After sb:\n");
		print_one(*stack_b, 'B');
	}
}

/*
** ss: sa and sb at the same time.
*/
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
    ft_putstr_fd("ss\n", 1);
	if (VISUALS)
	{
		print_debug_str("After ss:\n");
		print_stacks(*stack_a, *stack_b);
	}
}
