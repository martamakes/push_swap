/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 12:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/18 00:37:41 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_closest_target_b_to_a(t_stack *src, t_stack *dst)
{
	t_stack	*current;
	t_stack	*target;
	int		closest;

	target = NULL;
	closest = INT_MAX;
	current = dst;
	while (current)
	{
		if (current->index > src->index && current->index < closest)
		{
			closest = current->index;
			target = current;
		}
		current = current->next;
	}
	return (target);
}

static t_stack	*find_direct_target(t_stack *src, t_stack *dst, bool is_a_to_b)
{
	t_stack	*current;

	current = dst;
	while (current)
	{
		if (is_a_to_b && current->index == src->index - 1)
			return (current);
		if (!is_a_to_b && current->index == src->index + 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}

static t_stack	*find_target(t_stack *src, t_stack *dst, bool is_a_to_b)
{
	t_stack	*target;

	target = find_direct_target(src, dst, is_a_to_b);
	if (!target)
	{
		if (is_a_to_b)
			target = find_closest_target_a_to_b(src, dst);
		else
			target = find_closest_target_b_to_a(src, dst);
		if (!target)
		{
			if (is_a_to_b)
				target = find_biggest_node(dst);
			else
				target = find_smallest_node(dst);
		}
	}
	return (target);
}

void	find_target_positions(t_stack *src, t_stack *dst, bool is_a_to_b)
{
	t_stack	*current;
	t_stack	*target;

	current = src;
	while (current)
	{
		target = find_target(current, dst, is_a_to_b);
		if (target)
			current->target_pos = target->pos;
		else
			current->target_pos = 0;
		current = current->next;
	}
}
