/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:57:18 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/18 00:34:16 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_future_alignment(t_stack *a, t_stack *node)
{
	t_stack	*current;
	int		benefit;
	int		next_index;
	int		prev_index;

	benefit = 0;
	next_index = node->index + 1;
	prev_index = node->index - 1;
	current = a;
	while (current)
	{
		if (current->index == next_index || current->index == prev_index)
		{
			if (ft_abs(current->pos - node->target_pos) <= 1)
				benefit += 2;
			else if (ft_abs(current->pos
					- node->target_pos) < ft_abs(current->pos
					- current->target_pos))
				benefit += 1;
		}
		current = current->next;
	}
	return (benefit);
}

t_movement_impact	calculate_move_impact(t_stack *a, t_stack *b, t_stack *node)
{
	t_movement_impact	impact;
	int					consecutive_benefit;

	(void)b;
	impact.immediate_cost = abs(node->cost_a) + abs(node->cost_b);
	consecutive_benefit = calculate_future_alignment(a, node);
	impact.future_benefit = consecutive_benefit;
	impact.net_cost = impact.immediate_cost - impact.future_benefit;
	return (impact);
}
