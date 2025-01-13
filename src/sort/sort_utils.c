/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort_utils.c                                                            */
/*                                                                            */
/*   By: [your_username] <[your_email]>                                      */
/*                                                                            */
/*   Created: 2024/01/13 09:34:42                                            */
/*   Updated: 2024/01/13 09:34:42                                            */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	calculate_weighted_cost(t_node *node, int stack_size)
{
	int		distance;
	float	weight;
	int		base_cost;

	if (!node || stack_size <= 0)
		return (INT_MAX);
	base_cost = node->cost_a + node->cost_b;
	distance = ft_abs(node->position - node->index);
	weight = 1.0 + ((float)distance / stack_size);
	return ((int)(base_cost * weight));
}

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (true);
	current = stack->top;
	while (current->next)
	{
		if (current->index + 1 != current->next->index)
			return (false);
		current = current->next;
	}
	return (true);
}

void	find_cheapest_node(t_stack *stack_a)
{
	t_node	*current;
	int		min_cost;
	t_node	*cheapest;
	int		curr_cost;

	if (!stack_a || !stack_a->top)
		return ;
	current = stack_a->top;
	min_cost = INT_MAX;
	cheapest = NULL;
	while (current)
	{
		curr_cost = calculate_weighted_cost(current, stack_a->size);
		if (curr_cost < min_cost)
		{
			min_cost = curr_cost;
			cheapest = current;
		}
		current = current->next;
	}
	if (cheapest)
		cheapest->is_cheapest = true;
}