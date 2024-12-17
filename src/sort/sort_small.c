/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 12:11:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
** Finds the highest value in the stack
** Returns the highest value found
*/
static int	get_highest(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (0);
	highest = stack->value;
	while (stack)
	{
		if (stack->value > highest)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

/*
** Sorts a stack of three numbers using the minimum possible moves
** The algorithm checks the highest value's position and performs
** the necessary rotations and swaps to sort the stack
*/
void	sort_three(t_stack **stack)
{
	int	highest;

	if (!stack || !*stack || stack_size(*stack) < 2)
		return ;
	highest = get_highest(*stack);
	if ((*stack)->value == highest)
	{
		ra(stack);
		if (!is_sorted(*stack))
			sa(stack);
		return ;
	}
	if ((*stack)->next->value == highest)
	{
		rra(stack);
		if (!is_sorted(*stack))
			sa(stack);
		return ;
	}
	if (!is_sorted(*stack))
		sa(stack);
}
