/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:56:36 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/23 18:43:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (0);
}

/*
** Finds the position where a number from stack b should be inserted in stack a
** while maintaining ascending order
** Returns the position in stack a where the value should be placed
*/
static int	find_target_position_b_to_a(t_stack *a, int value)
{
	t_stack	*current;
	int		closest_smaller;
	int		closest_bigger;
	int		target_pos;

	closest_smaller = INT_MIN;
	closest_bigger = INT_MAX;
	current = a;
	target_pos = 0;
	while (current)
	{
		if (current->value < value && current->value > closest_smaller)
		{
			closest_smaller = current->value;
			target_pos = current->pos + 1;
		}
		if (current->value > value && current->value < closest_bigger)
			closest_bigger = current->value;
		current = current->next;
	}
	if (closest_bigger == INT_MAX && closest_smaller == INT_MIN)
		return (0);
	if (closest_bigger == INT_MAX)
		return (target_pos);
	return (find_pos(a, closest_bigger));
}

/*
** Finds the position where a number from stack a should be inserted in stack b
** to maintain order and minimize future moves
** Returns the position in stack b where the value should be placed
*/
static int	find_target_position_a_to_b(t_stack *b, int value)
{
	t_stack	*current;
	int		closest_smaller;
	int		closest_bigger;

	if (!b)
		return (0);
	closest_smaller = INT_MIN;
	closest_bigger = INT_MAX;
	current = b;
	while (current)
	{
		if (current->value < value && current->value > closest_smaller)
			closest_smaller = current->value;
		if (current->value > value && current->value < closest_bigger)
			closest_bigger = current->value;
		current = current->next;
	}
	if (closest_bigger != INT_MAX)
		return (find_pos(b, closest_bigger));
	if (closest_smaller != INT_MIN)
		return ((find_pos(b, closest_smaller) + 1) % stack_size(b));
	return (0);
}

/*
** General function that finds target position based on direction
** direction = 1: moving from A to B
** direction = 0: moving from B to A
*/
int	find_target_position(t_stack *src, t_stack *dst, int value)
{
	static t_stack	*last_src = NULL;

	if (src != last_src)
	{
		last_src = src;
		if (src && last_src && src->value == last_src->value)
			return (find_target_position_b_to_a(dst, value));
	}
	return (find_target_position_a_to_b(dst, value));
}
