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

static t_stack	*find_biggest_node(t_stack *stack)
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

static t_stack	*find_smallest_node(t_stack *stack)
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

/*
** A->B: target is closest smaller number, or top of biggest if none smaller
** B->A: target is closest larger number, or smallest if none larger
*/
void	find_target_positions(t_stack *src, t_stack *dst, bool is_a_to_b)
{
	t_stack *current_src;
	t_stack *current_dst;
	t_stack *target;
	int closest;

	current_src = src;
	while (current_src)
	{
		closest = is_a_to_b ? INT_MIN : INT_MAX;
		target = NULL;
		current_dst = dst;
		while (current_dst)
		{
			if (is_a_to_b && current_dst->index == current_src->index - 1)
			{
				target = current_dst;
				break ;
			}
			else if (!is_a_to_b && current_dst->index == current_src->index + 1)
			{
				target = current_dst;
				break ;
			}
			current_dst = current_dst->next;
		}
		if (!target)
		{
			current_dst = dst;
			while (current_dst)
			{
				if (is_a_to_b && current_dst->index < current_src->index
					&& current_dst->index > closest)
				{
					closest = current_dst->index;
					target = current_dst;
				}
				else if (!is_a_to_b && current_dst->index > current_src->index
					&& current_dst->index < closest)
				{
					closest = current_dst->index;
					target = current_dst;
				}
				current_dst = current_dst->next;
			}
		}
		if (!target)
		{
			if (is_a_to_b)
				target = find_biggest_node(dst);
			else
				target = find_smallest_node(dst);
			current_src->target_pos = target ? target->pos : 0;
		}
		else
			current_src->target_pos = target->pos;
		current_src = current_src->next;
	}
}
