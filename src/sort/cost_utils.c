/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 10:31:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/13 22:23:31 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	calculate_node_cost(t_stack *node, int size_curr, int size_target,
		bool is_a_to_b)
{
	if (!node)
		return ;
	if (is_a_to_b)
	{
		if (node->pos <= size_curr / 2)
			node->cost_a = node->pos;
		else
			node->cost_a = -(size_curr - node->pos);
		if (node->target_pos <= size_target / 2)
			node->cost_b = node->target_pos;
		else
			node->cost_b = -(size_target - node->target_pos);
	}
	else
	{
		if (node->pos <= size_curr / 2)
			node->cost_b = node->pos;
		else
			node->cost_b = -(size_curr - node->pos);
		if (node->target_pos <= size_target / 2)
			node->cost_a = node->target_pos;
		else
			node->cost_a = -(size_target - node->target_pos);
	}
	if (VISUALS)
		print_weighted_cost(node, calculate_weighted_cost(node));
}

/*t_stack	*get_cheapest_node(t_stack *stack, bool ascending)
{
	t_stack	*cheapest;
	t_stack	*current;
	int		min_cost;
	int		total_cost;

	if (!stack)
		return (NULL);
	cheapest = stack;
		min_cost = calculate_weighted_cost(stack);
	current = stack->next;
	while (current)
	{
				total_cost = calculate_weighted_cost(current);
		if (total_cost < min_cost || (total_cost == min_cost && 
			(ascending ? current->index < cheapest->index : 
			current->index > cheapest->index)))
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest)
		cheapest->is_cheapest = true;
	if (VISUALS)
		print_costs(stack, ascending ? 'B' : 'A');
	return (cheapest);
}*/
