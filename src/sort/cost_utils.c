/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:26:06 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 09:57:24 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_numbers_in_chunk(t_stack *stack, int start, int end)
{
    t_node *current;
    int count;

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

int calculate_position_cost(int pos, int stack_size, bool *reverse)
{
    *reverse = pos > stack_size / 2;
    return (*reverse ? stack_size - pos : pos);
}

// cost_utils.c
static int count_common_rotations(int cost_a, int cost_b)
{
    if (cost_a < cost_b)
        return (cost_a);
    return (cost_b);
}

static int calculate_rotate_cost(t_cost *cost, int *common_moves)
{
    int total;

    total = cost->cost_a + cost->cost_b;
    if (cost->rev_a == cost->rev_b)
    {
        *common_moves = count_common_rotations(cost->cost_a, cost->cost_b);
        total = *common_moves + (cost->cost_a - *common_moves) +
                (cost->cost_b - *common_moves);
    }
    return (total);
}

int calculate_total_cost(t_cost *cost)
{
    int total;
    int common_moves;

    common_moves = 0;
    total = calculate_rotate_cost(cost, &common_moves);
    if (cost->needs_swap && cost->can_ss)
        total--;
    return (total);
}
