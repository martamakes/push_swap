/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/13 22:32:41 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the position of the minimum value in the stack
** Returns the position (0-based index) of the minimum value
*/
int	get_min_pos(t_stack *stack)
{
	int		min;
	int		pos;
	int		min_pos;
	t_stack	*current;

	if (!stack)
		return (0);
	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	current = stack;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

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
	while (min_pos > 0 && !is_sorted(*a))
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

	if (is_sorted(*a))
		return;
		
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else
	{
		while (size > 3 && !is_sorted(*a))
		{
			mid = size / 2;
			move_min_to_top(a, get_min_pos(*a), mid);
			if (!is_sorted(*a))
			{
				pb(a, b);
				size--;
			}		
		}
		if (!is_sorted(*a))
			sort_three(a);
		while (*b)
			pa(a, b);
	}
}
