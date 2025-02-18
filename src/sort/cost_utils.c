/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:31:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/17 07:43:43 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_stack_cost(int *cost, int pos, int size)
{
	if (pos <= size / 2)
		*cost = pos;
	else
		*cost = -(size - pos);
}

void	calculate_node_cost(t_stack *node, int size_curr, int size_target,
		bool is_a_to_b)
{
	if (!node)
		return ;
	if (is_a_to_b)
	{
		calculate_stack_cost(&node->cost_a, node->pos, size_curr);
		calculate_stack_cost(&node->cost_b, node->target_pos, size_target);
	}
	else
	{
		calculate_stack_cost(&node->cost_b, node->pos, size_curr);
		calculate_stack_cost(&node->cost_a, node->target_pos, size_target);
	}
	if (VISUALS)
		print_weighted_cost(node, calculate_weighted_cost(node));
}
