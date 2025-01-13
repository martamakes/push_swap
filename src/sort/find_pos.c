/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 08:56:36 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/13 18:30:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_highest_index_pos(t_stack *stack)
{
	t_stack	*current;
	int		highest_index;
	int		highest_pos;

	if (!stack)
		return (0);
	current = stack;
	highest_index = INT_MIN;
	highest_pos = 0;
	while (current)
	{
		if (current->index > highest_index)
		{
			highest_index = current->index;
			highest_pos = current->pos;
		}
		current = current->next;
	}
	return (highest_pos);
}

static int	get_lowest_index_pos(t_stack *stack)
{
	t_stack	*current;
	int		lowest_index;
	int		lowest_pos;

	if (!stack)
		return (0);
	current = stack;
	lowest_index = INT_MAX;
	lowest_pos = 0;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}

static int	find_target_in_descending_stack(t_stack *a_node, t_stack *b)
{
	t_stack	*current;
	int		target_index;
	int		target_pos;

	if (!b)
		return (0);
	target_index = INT_MIN;
	target_pos = 0;
	current = b;
	while (current)
	{
		if (current->index < a_node->index && current->index > target_index)
		{
			target_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	if (target_index == INT_MIN)
		return (get_highest_index_pos(b));
	return (target_pos);
}

int	find_target_pos_a_to_b(t_stack *a_node, t_stack *stack_b)
{
	return (find_target_in_descending_stack(a_node, stack_b));
}

int	find_target_pos_b_to_a(t_stack *b_node, t_stack *stack_a)
{
	t_stack	*current;
	int		lowest_bigger_index;
	int		target_pos;

	if (!stack_a)
		return (0);
	current = stack_a;
	lowest_bigger_index = INT_MAX;
	target_pos = get_lowest_index_pos(stack_a);
	while (current)
	{
		if (current->index > b_node->index && 
			current->index < lowest_bigger_index)
		{
			lowest_bigger_index = current->index;
			target_pos = current->pos;
		}
		current = current->next;
	}
	return (target_pos);
}
