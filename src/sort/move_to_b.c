/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:24:41 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 10:27:01 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    handle_empty_chunk(t_stack *a, t_chunk_info *chunk)
{
    chunk->current++;
    if (chunk->current >= chunk->total)
        chunk->current = 0;
    get_chunk_limits(a, chunk->current, &chunk->start, &chunk->end);
}

void    move_to_b(t_stack *a, t_stack *b, t_chunk_info *chunk)
{
    int numbers_in_chunk;

    while (a->size > 3)
    {
        numbers_in_chunk = count_numbers_in_chunk(a, chunk->start, chunk->end);
        if (numbers_in_chunk == 0)
        {
            handle_empty_chunk(a, chunk);
            continue;
        }
        push_optimal_number(a, b, chunk->start, chunk->end);
    }
    sort_three(a);
}
