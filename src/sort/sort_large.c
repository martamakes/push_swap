/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:14:26 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 13:44:22 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_closest_in_chunk(t_stack *a, t_chunk *chunk, int *rotate_up)
{
    t_node  *curr_top;
    t_node  *curr_bottom;
    int     moves_top;
    int     moves_bottom;

    curr_top = a->top;
    curr_bottom = a->bottom;
    moves_top = 0;
    moves_bottom = 0;

    while (curr_top && moves_top <= a->size / 2)
    {
        if (is_in_current_chunk(curr_top->value, chunk))
        {
            *rotate_up = 1;
            return moves_top;
        }
        curr_top = curr_top->next;
        moves_top++;
    }

    while (curr_bottom && moves_bottom <= a->size / 2)
    {
        if (is_in_current_chunk(curr_bottom->value, chunk))
        {
            *rotate_up = 0;
            return moves_bottom + 1;
        }
        curr_bottom = curr_bottom->prev;
        moves_bottom++;
    }
    return (-1);
}

static void rotate_to_closest(t_stack *a, int moves, int up)
{
    while (moves--)
    {
        if (up)
            ra(a);
        else
            rra(a);
    }
}

static void push_chunk_to_b(t_stack *a, t_stack *b, t_chunk *chunk)
{
    int rotate_up;
    int moves;
    int pushed;

    pushed = 0;
    while (pushed < chunk->chunk_size && a->size > 3)
    {
        moves = find_closest_in_chunk(a, chunk, &rotate_up);
        if (moves == -1)
            break;
        
        rotate_to_closest(a, moves, rotate_up);
        if (b->size > 0 && b->top->value < b->top->next->value)
            sb(b);
        pb(a, b);
        pushed++;
    }
}

void    sort_large(t_stack *a, t_stack *b)
{
    t_chunk chunk;

    if (!a || !b || a->size <= 5)
        return ;

    // Inicializar información de chunks
    init_chunk_info(a, &chunk);

    // Empujar números a B por chunks
    while (chunk.current < chunk.num_chunks && a->size > 3)
    {
        push_chunk_to_b(a, b, &chunk);
        chunk.current++;
    }

    // Ordenar los últimos 3 números en A
    sort_three(a, 'a');

    // Devolver números a A de manera ordenada
    push_back(a, b);

    // Rotar hasta que el mínimo esté arriba
    rotate_to_min(a);
}
