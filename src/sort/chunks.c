/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:11:39 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:13:33 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int calculate_optimal_chunks(int size)
{
    if (size <= 100)
        return (5 + size / 25);
    return (11 + size / 50);
}

int	is_in_chunk(int value, int start, int end)
{
	return (value >= start && value <= end);
}

void get_chunk_limits(t_stack *stack, int chunk_index, int *start, int *end)
{
    int     min;
    int     max;
    int     total_chunks;
    double  chunk_size;
    
    get_stack_bounds(stack, &min, &max);
    total_chunks = calculate_optimal_chunks(stack->size);
    chunk_size = (double)(max - min + 1) / total_chunks;
    
    *start = min + (int)(chunk_size * chunk_index);
    *end = min + (int)(chunk_size * (chunk_index + 1)) - 1;
    
    if (chunk_index == total_chunks - 1)
        *end = max;
}
