/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 07:44:17 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/19 18:21:12 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	calculate_weighted_cost(t_stack *node)
{
	int	weighted_cost;

	weighted_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
	if (VISUALS)
		print_weighted_cost(node, weighted_cost);
	return (weighted_cost);
}

static int	compare_nodes(t_stack *current, t_stack *cheapest, bool ascending)
{
	int	comp_value;

	if (cheapest)
		comp_value = cheapest->value;
	else if (ascending)
		comp_value = INT_MAX;
	else
		comp_value = INT_MIN;
	if (ascending)
		return (current->value < comp_value);
	return (current->value > comp_value);
}

t_stack	*get_cheapest_node(t_stack *stack, bool ascending)
{
	t_stack	*current;
	t_stack	*cheapest;
	int		min_cost;
	int		current_cost;

	if (!stack)
		return (NULL);
	current = stack;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (current)
	{
		current_cost = calculate_weighted_cost(current);
		if (compare_nodes(current, cheapest, ascending))
		{
			if (current_cost < min_cost)
			{
				min_cost = current_cost;
				cheapest = current;
			}
		}
		current = current->next;
	}
	return (cheapest);
}
