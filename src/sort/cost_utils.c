/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:26:06 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:15:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_cost(t_cost *cost)
{
    cost->cost_a = 0;
    cost->cost_b = 0;
    cost->pos_a = 0;
    cost->pos_b = 0;
    cost->total_cost = 0;
    cost->rev_a = false;
    cost->rev_b = false;
    cost->can_ss = false;
    cost->needs_swap = false;
    cost->value = 0;
}

int    count_numbers_in_chunk(t_stack *stack, int start, int end)
{
    t_node  *current;
    int     count;

    count = 0;
    current = stack->top;
    while (current)
    {
        if (is_in_chunk(current->value, start, end))
            count++;
        current = current->next;
    }
    return (count);
}

int    calculate_position_cost(int pos, int stack_size, bool *reverse)
{
    *reverse = pos > stack_size / 2;
    return (*reverse ? stack_size - pos : pos);
}

int    calculate_total_cost(t_cost *cost)
{
    int total;
    int common_moves;

    total = cost->cost_a + cost->cost_b;
    common_moves = 0;
    if (cost->rev_a == cost->rev_b)
    {
        if (cost->cost_a < cost->cost_b)
            common_moves = cost->cost_a;
        else
            common_moves = cost->cost_b;
        total = common_moves + (cost->cost_a - common_moves) + 
            (cost->cost_b - common_moves);
    }
    if (cost->needs_swap && cost->can_ss)
        total--;
    return (total);
}
