/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimal_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:11:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 10:18:53 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_position_in_b(t_stack *b, int value, t_cost *cost)
{
	t_node	*current;
	t_node	*next;
	int		pos;

	if (!b->top)
		return ;
	pos = 0;
	current = b->top;
	while (current)
	{
		next = current->next;
		if (!next)
			next = b->top;
		if (value > current->value && value < next->value)
			break ;
		pos++;
		current = current->next;
		if (current == b->top)
			break ;
	}
	cost->pos_b = pos;
	cost->cost_b = calculate_position_cost(pos, b->size, &cost->rev_b);
}

static void	calculate_move_cost(t_stack *a, t_stack *b, int pos_a, t_cost *cost)
{
	init_cost(cost);
	cost->pos_a = pos_a;
	cost->cost_a = calculate_position_cost(pos_a, a->size, &cost->rev_a);
	find_position_in_b(b, get_value_at_position(a, pos_a), cost);
}

static void	find_best_number(t_stack *a, t_stack *b, int start, int end, 
				t_cost *best)
{
	t_node	*current;
	t_cost	curr_cost;
	int		pos;
	int		curr_total;
	int		best_total;

	pos = 0;
	current = a->top;
	best->cost_a = INT_MAX;
	while (current)
	{
		if (is_in_chunk(current->value, start, end))
		{
			calculate_move_cost(a, b, pos, &curr_cost);
			curr_total = calculate_total_cost(&curr_cost);
			best_total = calculate_total_cost(best);
			if (curr_total < best_total)
				*best = curr_cost;
		}
		pos++;
		current = current->next;
	}
}

void	push_optimal_number(t_stack *a, t_stack *b, int start, int end)
{
	t_cost	best_cost;

	init_cost(&best_cost);
	find_best_number(a, b, start, end, &best_cost);
	if (best_cost.cost_a != INT_MAX)
	{
		execute_moves(a, b, &best_cost);
		pb(a, b);
	}
}
