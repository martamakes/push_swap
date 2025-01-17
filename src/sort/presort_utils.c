/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:48:42 by mvigara-          #+#    #+#             */
/*   Updated: 2025/01/18 00:36:48 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_out_of_place(t_stack *stack)
{
	int		count;
	int		expected_index;
	t_stack	*current;

	count = 0;
	expected_index = 0;
	current = stack;
	while (current)
	{
		if (current->index != expected_index)
			count++;
		expected_index++;
		current = current->next;
	}
	return (count);
}

static void	update_min_candidate(t_stack *current, int *pos, int *min_idx,
		int *first)
{
	*min_idx = current->index;
	*first = *pos;
}

static void	update_second_min(t_stack *current, int *pos, int *second_min_idx,
		int *second)
{
	*second_min_idx = current->index;
	*second = *pos;
}

void	find_min_candidates(t_stack *stack, int *first, int *second)
{
	int		min_idx;
	int		second_min_idx;
	t_stack	*current;
	int		pos;

	min_idx = INT_MAX;
	second_min_idx = INT_MAX;
	pos = 0;
	current = stack;
	while (current && pos < stack_size(stack) / 2)
	{
		if (current->index < min_idx)
		{
			second_min_idx = min_idx;
			*second = *first;
			update_min_candidate(current, &pos, &min_idx, first);
		}
		else if (current->index < second_min_idx)
			update_second_min(current, &pos, &second_min_idx, second);
		current = current->next;
		pos++;
	}
}

int	is_position_optimal(int pos, int size)
{
	if (pos <= 1)
		return (1);
	if (pos >= size - 1)
		return (1);
	return (0);
}
