/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:56:06 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/03 07:49:42 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_num_in_range_pos(t_stack *a, int min, int max)
{
	t_node	*current;
	int		pos;
	int		best_pos;
	int		best_val;

	current = a->top;
	pos = 0;
	best_pos = -1;
	best_val = INT_MAX;
	while (current)
	{
		if (current->value >= min && current->value <= max 
			&& current->value < best_val)
		{
			best_val = current->value;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (best_pos);
}

static void	rotate_to_pos(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos--)
			ra(a);
	else
		while (pos++ < a->size)
			rra(a);
}

static void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	pos;

	while (a->size)
	{
		pos = get_num_in_range_pos(a, min, max);
		if (pos == -1)
			break ;
		rotate_to_pos(a, pos);
		pb(a, b);
	}
}

static void	init_chunk_values(t_stack *a, int *min, int *max)
{
	t_node	*current;

	*min = a->top->value;
	*max = a->top->value;
	current = a->top;
	while (current)
	{
		if (current->value < *min)
			*min = current->value;
		if (current->value > *max)
			*max = current->value;
		current = current->next;
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	min;
	int	max;
	int	range;
	int	chunk_min;
	int	chunk_max;

	init_chunk_values(a, &min, &max);
	range = max - min;
	chunk_size = range / 5;
	chunk_min = min;
	while (chunk_min < max)
	{
		chunk_max = chunk_min + chunk_size;
		push_chunk_to_b(a, b, chunk_min, chunk_max);
		chunk_min = chunk_max + 1;
	}
	while (b->size)
		pa(a, b);
}
