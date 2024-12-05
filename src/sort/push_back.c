/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:11:42 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:28:09 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    calculate_push_cost(t_stack *b, t_cost *cost)
{
    cost->pos_b = get_max_pos(b);
    cost->cost_b = calculate_position_cost(cost->pos_b, b->size, 
        &cost->rev_b);
    cost->pos_a = 0;
    cost->cost_a = 0;
}

static bool is_consecutive_descending(t_node *node)
{
    if (!node || !node->next)
        return (true);
    return (node->value == node->next->value + 1);
}

void    move_back_to_a(t_stack *a, t_stack *b)
{
    t_cost  cost;
    bool    rotate_optimized;

    while (b->size > 0)
    {
        init_cost(&cost);
        rotate_optimized = false;
        if (is_optimal_double_swap(a, b))
        {
            ss(a, b);
            continue;
        }
        if (b->size > 1 && is_consecutive_descending(b->top))
        {
            rotate_optimized = true;
            while (b->size > 0 && is_consecutive_descending(b->top))
                pa(a, b);
        }
        if (!rotate_optimized)
        {
            calculate_push_cost(b, &cost);
            execute_optimal_moves(a, b, &cost);
            pa(a, b);
        }
    }
}