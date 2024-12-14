/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:10:11 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/14 20:12:13 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_chunk_info(t_stack *a, t_chunk *chunk)
{
    int min;
    int max;
    
    if (!a || !chunk)
        return ;
    
    get_stack_bounds(a, &min, &max);
    chunk->min = min;
    chunk->max = max;
    
    // Ajuste dinámico del número de chunks
    if (a->size <= 100)
    {
        // Para 50-100 números, usamos 5 chunks
        chunk->num_chunks = 5;
    }
    else
    {
        // Para >100 números, usamos más chunks pero de manera proporcional
        chunk->num_chunks = 11;
    }
    
    // El tamaño de chunk es ahora más preciso
    chunk->chunk_size = (max - min + chunk->num_chunks) / chunk->num_chunks;
    chunk->current = 0;
}

int    get_chunk_start(t_chunk *chunk)
{
    if (!chunk)
        return (0);
    return (chunk->min + (chunk->current * chunk->chunk_size));
}

int    get_chunk_end(t_chunk *chunk)
{
    if (!chunk)
        return (0);
    return (chunk->min + ((chunk->current + 1) * chunk->chunk_size) - 1);
}

bool    is_in_current_chunk(int value, t_chunk *chunk)
{
    int start;
    int end;

    if (!chunk)
        return (false);
    start = get_chunk_start(chunk);
    end = get_chunk_end(chunk);
    return (value >= start && value <= end);
}


