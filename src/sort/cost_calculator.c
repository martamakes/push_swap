/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:30:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:15:51 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_move_costs(t_stack *a, t_stack *b, t_cost *cost)
{
    cost->cost_a = calculate_position_cost(cost->pos_a, a->size, &cost->rev_a);
    cost->cost_b = calculate_position_cost(cost->pos_b, b->size, &cost->rev_b);
    
    // Optimizar movimientos simultáneos
    int simultaneous = 0;
    if (cost->rev_a == cost->rev_b)
        simultaneous = ft_min(cost->cost_a, cost->cost_b);
    
    cost->total_cost = cost->cost_a + cost->cost_b - simultaneous;
    
    // Optimizar swaps dobles
    if (cost->needs_swap && can_double_swap(a, b))
    {
        cost->can_ss = true;
        cost->total_cost--;
    }
}
