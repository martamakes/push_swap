/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/18 00:37:41 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest_node(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	biggest = stack;
	current = stack->next;
	while (current)
	{
		if (current->index > biggest->index)
			biggest = current;
		current = current->next;
	}
	return (biggest);
}

t_stack	*find_smallest_node(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	smallest = stack;
	current = stack->next;
	while (current)
	{
		if (current->index < smallest->index)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_stack	*find_closest_target_a_to_b(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	t_stack	*target;
	int		closest;

	target = NULL;
	closest = INT_MIN;
	current = dst;
	while (current)
	{
		if (current->index < src->index && current->index > closest)
		{
			closest = current->index;
			target = current;
		}
		current = current->next;
	}
	return (target);
}
