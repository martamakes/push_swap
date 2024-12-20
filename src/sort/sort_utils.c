/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:58:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/19 09:43:22 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Updates position values for all nodes in a stack
** This is crucial for cost calculations
*/
void	update_positions(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	current = stack;
	while (current)
	{
		current->pos = i;
		i++;
		current = current->next;
	}
}

/*
** Gets total cost of moving elements to their target positions
** cost_a: moves needed in stack a
** cost_b: moves needed in stack b
*/
void	get_cost(t_stack *a, t_stack *b)
{
	int		size_a;
	int		size_b;
	t_stack	*current;

	size_a = stack_size(a);
	size_b = stack_size(b);
	current = a;
	while (current)
	{
		current->cost_a = current->pos;
		if (current->pos > size_a / 2)
			current->cost_a = -(size_a - current->pos);
		current->cost_b = current->target_pos;
		if (current->target_pos > size_b / 2)
			current->cost_b = -(size_b - current->target_pos);
		current = current->next;
	}
}

/*
** Gets target positions for each element in stack_a
** This helps determine where each element should go in stack_b
*/
void	get_target_positions(t_stack *a, t_stack *b)
{
	t_stack	*current;

	current = a;
	update_positions(a);
	update_positions(b);
	while (current)
	{
		current->target_pos = find_target_position(a, b, current->value);
		current = current->next;
	}
}

/*
** Finds the element with the cheapest cost to move
** Returns the node with the lowest absolute combined cost
*/
t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*current;
	int		lowest_cost;
	int		cost;

	if (!stack)
		return (NULL);
	cheapest = stack;
	lowest_cost = ft_abs(stack->cost_a) + ft_abs(stack->cost_b);
	current = stack->next;
	while (current)
	{
		cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
		if (cost < lowest_cost)
		{
			lowest_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

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
