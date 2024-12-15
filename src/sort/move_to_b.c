/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:24:41 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 04:32:12 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  check_bottom_positions(t_stack *a, t_chunk *chunk, int top_limit)
{
    t_node  *bottom;
    int     pos_bottom;

    bottom = a->bottom;
    pos_bottom = 0;
    while (bottom && pos_bottom < top_limit)
    {
        if (is_in_current_chunk(bottom->value, chunk))
            return (a->size - pos_bottom - 1);
        pos_bottom++;
        bottom = bottom->prev;
    }
    return (-1);
}

static int  get_closest_in_chunk(t_stack *a, t_chunk *chunk)
{
    t_node  *current;
    int     pos_top;
    int     bottom_pos;

    if (!a || !chunk || !a->top)
        return (-1);
    current = a->top;
    pos_top = 0;
    while (current && pos_top <= a->size / 2)
    {
        if (is_in_current_chunk(current->value, chunk))
        {
            bottom_pos = check_bottom_positions(a, chunk, pos_top);
            if (bottom_pos != -1)
                return (bottom_pos);
            return (pos_top);
        }
        pos_top++;
        current = current->next;
    }
    return (-1);
}

static void rotate_to_position(t_stack *a, int pos)
{
    int     middle;
    int     moves;

    if (!a || pos < 0)
        return ;
    middle = a->size / 2;
    if (pos <= middle)
    {
        moves = pos;
        while (moves > 0)
        {
            ra(a);
            moves--;
        }
        return ;
    }
    moves = a->size - pos;
    while (moves > 0)
    {
        rra(a);
        moves--;
    }
}

static void    optimize_b_after_push(t_stack *b)
{
    if (!b || b->size < 2)
        return ;
    if (b->top->value < b->top->next->value)
        sb(b);
}

void    push_chunks_to_b(t_stack *a, t_stack *b, t_chunk *chunk)
{
    int pos;
    int moved;

    if (!a || !b || !chunk)
        return ;
    while (chunk->current < chunk->num_chunks)
    {
        moved = 0;
        pos = get_closest_in_chunk(a, chunk);
        while (pos != -1)
        {
            rotate_to_position(a, pos);
            pb(a, b);
            optimize_b_after_push(b);
            moved++;
            pos = get_closest_in_chunk(a, chunk);
        }
        if (moved == 0)
            chunk->current++;
    }
}
