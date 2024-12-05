/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:11:39 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 10:19:27 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_max(t_stack *stack, int *min, int *max)
{
	t_node	*current;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	*min = current->value;
	*max = current->value;
	while (current)
	{
		if (current->value < *min)
			*min = current->value;
		if (current->value > *max)
			*max = current->value;
		current = current->next;
	}
}

void	get_chunk_limits(t_stack *stack, int chunk_index, int *start, int *end)
{
	int		min;
	int		max;
	int		total_chunks;
	long	range;

	find_min_max(stack, &min, &max);
	total_chunks = stack->size <= 100 ? 5 : 11;
	range = ((long)max - (long)min) / total_chunks;
	*start = min + (range * chunk_index);
	*end = min + (range * (chunk_index + 1));
	if (chunk_index == total_chunks - 1)
		*end = max;
}

int	is_in_chunk(int value, int start, int end)
{
	return (value >= start && value <= end);
}
