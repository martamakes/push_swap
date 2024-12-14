/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:24:41 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/14 18:40:37 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static int  find_optimal_number(t_stack *a, int start, int end, t_cost *best)
{
    t_node  *current;
    int     pos;
    t_cost  cost;

    pos = 0;
    current = a->top;
    while (current)
    {
        if (current->value >= start && current->value <= end)
        {
            init_cost(&cost);
            cost.pos_a = pos;
            calculate_move_costs(a, NULL, &cost);
            if (cost.total_cost < best->total_cost)
            {
                *best = cost;
                best->value = current->value;
            }
        }
        current = current->next;
        pos++;
    }
    return (best->total_cost != INT_MAX);
}

static void check_position(t_stack *a, t_stack *b, t_cost *cost, int pos)
{
    t_node  *node;

    node = get_value_at_position(a, pos);
    if (!node)
        return ;
    cost->pos_a = pos;
    cost->value = node->value;
    calculate_move_costs(a, b, cost);
}
*/

static void check_chunk_positions(t_stack *a, t_stack *b, t_cost *best,
    int *limits)
{
    t_node  *current;
    t_cost  curr_cost;
    int     pos;

    current = a->top;
    pos = 0;
    while (current)
    {
        if (is_in_chunk(current->value, limits[0], limits[1]))
        {
            init_cost(&curr_cost);
            check_position(a, b, &curr_cost, pos);
            if (curr_cost.total_cost < best->total_cost)
                *best = curr_cost;
        }
        current = current->next;
        pos++;
    }
}

void    move_to_b(t_stack *a, t_stack *b, t_chunk_info *chunk)
{
    t_cost  best;
    
    if (!a || !b || !chunk || a->size <= 3)
        return ;
    while (a->size > 3)
    {
        get_chunk_limits(a, chunk);
        init_cost(&best);
        best.total_cost = INT_MAX;
        if (count_numbers_in_chunk(a, chunk->start, chunk->end) == 0)
        {
            chunk->current++;
            if (chunk->current >= chunk->total)
                chunk->current = 0;
            continue ;
        }
        push_optimal_number(a, b, chunk->start, chunk->end);
    }
    sort_three(a);
}
