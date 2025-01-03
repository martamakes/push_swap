/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 08:39:33 by mvigara-         ###   ########.fr       */
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
	if (is_sorted(*stack))
		return ;
	highest = get_highest(*stack);
	if ((*stack)->value == highest)
	{
		ra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else if ((*stack)->next->value == highest)
	{
		rra(stack);
		if (!is_sorted(*stack))
			sa(stack);
	}
	else if (!is_sorted(*stack))
		sa(stack);
}

static void	move_min_to_top(t_stack **a, int min_pos, int mid)
{
	while (min_pos > 0)
	{
		if (min_pos <= mid)
			ra(a);
		else
			rra(a);
		min_pos = get_min_pos(*a);
	}
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	int	mid;

	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (size > 3)
		{
			mid = size / 2;
			move_min_to_top(a, get_min_pos(*a), mid);
			pb(a, b);
			size--;
		}
		sort_three(a);
		while (*b)
			pa(a, b);
	}
}
