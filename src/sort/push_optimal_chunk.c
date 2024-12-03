/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_optimal_chunk.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:13:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/03 08:23:53 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_chunk_limits(int chunk_num, int total_chunks, 
	int *min, int *max)
{
	long	chunk_range;
	long	min_long;

	chunk_range = ((long)INT_MAX - (long)INT_MIN) / total_chunks;
	min_long = (long)INT_MIN + (chunk_range * chunk_num);
	*min = (int)min_long;
	*max = (int)(min_long + chunk_range - 1);
}

static int	get_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

static int	check_value_in_chunk(int value, int min, int max)
{
	if (value >= min && value <= max)
		return (1);
	return (0);
}

static int	find_best_number_position(t_stack *a, int chunk_num, 
	int total_chunks)
{
	t_node	*current;
	int		pos;
	int		best_pos;
	int		best_cost;
	int		current_cost;
	int		min;
	int		max;

	pos = 0;
	best_pos = -1;
	best_cost = INT_MAX;
	get_chunk_limits(chunk_num, total_chunks, &min, &max);
	current = a->top;
	while (current)
	{
		if (check_value_in_chunk(current->value, min, max))
		{
			current_cost = get_rotation_cost(pos, a->size);
			if (current_cost < best_cost)
			{
				best_cost = current_cost;
				best_pos = pos;
			}
		}
		current = current->next;
		pos++;
	}
	return (best_pos);
}

static void	do_rotation(t_stack *stack, char stack_name, int dir)
{
	if (dir > 0)
	{
		if (stack_name == 'a')
			ra(stack);
		else
			rb(stack);
	}
	else
	{
		if (stack_name == 'a')
			rra(stack);
		else
			rrb(stack);
	}
}

static void	rotate_to_position(t_stack *stack, int pos, char stack_name)
{
	int	rot_dir;

	if (pos <= stack->size / 2)
		rot_dir = 1;
	else
	{
		rot_dir = -1;
		pos = stack->size - pos;
	}
	while (pos > 0)
	{
		do_rotation(stack, stack_name, rot_dir);
		pos--;
	}
}

void	push_optimal_chunk(t_stack *a, t_stack *b, int chunk_num, 
	int total_chunks)
{
	int	pos;
	int	numbers_in_chunk;

	numbers_in_chunk = a->size / total_chunks;
	while (numbers_in_chunk > 0)
	{
		pos = find_best_number_position(a, chunk_num, total_chunks);
		if (pos == -1)
			break ;
		rotate_to_position(a, pos, 'a');
		pb(a, b);
		numbers_in_chunk--;
	}
}
