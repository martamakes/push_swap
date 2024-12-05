/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:24:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 09:58:26 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// execute_moves.c
static void execute_swap_moves(t_stack *a, t_stack *b, t_cost *cost)
{
    if (cost->needs_swap)
    {
        if (cost->can_ss)
            ss(a, b);
        else
            sa(a);
    }
}

static void execute_double_rotations(t_stack *a, t_stack *b, t_cost *cost)
{
    while (cost->cost_a > 0 && cost->cost_b > 0 && 
           cost->rev_a == cost->rev_b)
    {
        if (cost->rev_a)
            rrr(a, b);
        else
            rr(a, b);
        cost->cost_a--;
        cost->cost_b--;
    }
}

void execute_moves(t_stack *a, t_stack *b, t_cost *cost)
{
    execute_double_rotations(a, b, cost);
    while (cost->cost_a-- > 0)
    {
        if (cost->rev_a)
            rra(a);
        else
            ra(a);
    }
    while (cost->cost_b-- > 0)
    {
        if (cost->rev_b)
            rrb(b);
        else
            rb(b);
    }
    execute_swap_moves(a, b, cost);
}
