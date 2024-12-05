/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:24:01 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:16:58 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// En execute_moves.c
void    execute_optimal_moves(t_stack *a, t_stack *b, t_cost *cost)
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
    complete_rotations(a, cost->cost_a, cost->rev_a);
    complete_rotations(b, cost->cost_b, cost->rev_b);
}
