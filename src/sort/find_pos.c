/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:56:36 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/23 22:51:42 by mvigara-         ###   ########.fr       */
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
** Finds target position for a node from stack a to stack b
** Looks for the closest smaller number in b, or the largest if none is smaller
** Returns the position where the node should be placed in stack b
*/
static int	get_highest_pos(t_stack *stack)
{
	t_stack	*current;
	int		highest_val;
	int		highest_pos;

	current = stack;
	highest_val = INT_MIN;
	highest_pos = 0;
	while (current)
	{
		if (current->value > highest_val)
		{
			highest_val = current->value;
			highest_pos = current->pos;
		}
		current = current->next;
	}
	return (highest_pos);
}

int	find_target_pos_a_to_b(t_stack *a_node, t_stack *stack_b)
{
	t_stack	*current;
	int		target_index;
	int		closest_smaller_index;

	closest_smaller_index = -1;
	current = stack_b;
	while (current)
	{
		if (current->index < a_node->index && 
			(closest_smaller_index == -1 || 
			 current->index > closest_smaller_index))
		{
			closest_smaller_index = current->index;
			target_index = current->pos;
		}
		current = current->next;
	}
	if (closest_smaller_index == -1)
		return (get_highest_pos(stack_b));
	return (target_index);
}

/*
** Finds target position for a node from stack b to stack a
** Looks for the closest larger number in a, or the smallest if none is larger
** Returns the position where the node should be placed in stack a
*/
static int	get_lowest_pos(t_stack *stack)
{
	t_stack	*current;
	int		lowest_val;
	int		lowest_pos;

	current = stack;
	lowest_val = INT_MAX;
	lowest_pos = 0;
	while (current)
	{
		if (current->value < lowest_val)
		{
			lowest_val = current->value;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}

int	find_target_pos_b_to_a(t_stack *b_node, t_stack *stack_a)
{
	t_stack	*current;
	int		target_index;
	int		closest_larger_index;

	closest_larger_index = -1;
	current = stack_a;
	while (current)
	{
		if (current->index > b_node->index && 
			(closest_larger_index == -1 || 
			 current->index < closest_larger_index))
		{
			closest_larger_index = current->index;
			target_index = current->pos;
		}
		current = current->next;
	}
	if (closest_larger_index == -1)
		return (get_lowest_pos(stack_a));
	return (target_index);
}
