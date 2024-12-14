/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:24:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 15:17:35 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    calculate_optimal_rotations(t_stack *a, t_stack *b, t_cost *cost)
{
    int     a_pos;
    int     b_pos;
    bool    rev_a;
    bool    rev_b;

    a_pos = cost->pos_a;
    b_pos = cost->pos_b;
    cost->cost_a = calculate_position_cost(a_pos, a->size, &rev_a);
    cost->cost_b = calculate_position_cost(b_pos, b->size, &rev_b);
    cost->rev_a = rev_a;
    cost->rev_b = rev_b;
}

void    complete_rotations(t_stack *stack, int count, int reverse)
{
    while (count > 0)
    {
        if (reverse)
            rra(stack);
        else
            ra(stack);
        count--;
    }
}

void    execute_optimal_moves(t_stack *a, t_stack *b, t_cost *cost)
{
    calculate_optimal_rotations(a, b, cost);
    if (cost->needs_swap && is_optimal_double_swap(a, b))
    {
        ss(a, b);
        cost->can_ss = true;
    }
    while (cost->cost_a > 0 && cost->cost_b > 0 && cost->rev_a == cost->rev_b)
    {
        if (cost->rev_a)
            rrr(a, b);
        else
            rr(a, b);
        cost->cost_a--;
        cost->cost_b--;
    }
    complete_rotations(a, cost->cost_a, cost->rev_a);
    complete_rotations(b, cost->cost_b, cost->rev_b);
}
