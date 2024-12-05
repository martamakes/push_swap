/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:26:34 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:27:16 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_optimal_double_swap(t_stack *a, t_stack *b)
{
    if (!a || !b || a->size < 2 || b->size < 2)
        return (false);
    if (would_improve_a(a) && would_improve_b(b, a))
        return (true);
    return (false);
}

bool    would_improve_a(t_stack *a)
{
    t_node  *first;
    t_node  *second;
    t_node  *third;

    if (!a || a->size < 2)
        return (false);
    first = a->top;
    second = first->next;
    third = second ? second->next : NULL;
    if (!first || !second)
        return (false);
    if (!third)
        return (first->value > second->value);
    if (first->value > second->value && second->value < third->value)
        return (true);
    return (false);
}

bool    would_improve_b(t_stack *b, t_stack *a)
{
    t_node  *first;
    t_node  *second;
    t_cost  cost_before;
    t_cost  cost_after;

    if (!b || b->size < 2)
        return (false);
    first = b->top;
    second = first->next;
    init_cost(&cost_before);
    calculate_target_position(a, first->value, &cost_before);
    init_cost(&cost_after);
    calculate_target_position(a, second->value, &cost_after);
    if (cost_after.total_cost < cost_before.total_cost)
        return (true);
    return (false);
}
