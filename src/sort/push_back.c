/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:11:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 10:18:35 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	current = stack->top;
	max = current->value;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

static void	calculate_push_cost(t_stack *a, t_stack *b, t_cost *cost)
{
	int	max_pos;

	max_pos = find_max_pos(b);
	cost->pos_b = max_pos;
	cost->cost_b = calculate_position_cost(max_pos, b->size, &cost->rev_b);
	cost->pos_a = 0;
	cost->cost_a = 0;
}

void	move_back_to_a(t_stack *a, t_stack *b)
{
	t_cost	cost;

	while (b->size > 0)
	{
		init_cost(&cost);
		calculate_push_cost(a, b, &cost);
		execute_moves(a, b, &cost);
		pa(a, b);
	}
}
