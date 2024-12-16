/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:39:21 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 12:39:24 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    calculate_cost(t_stack *a, t_stack *b)
{
    t_node  *current;
    int     size_a;
    int     size_b;

    current = b->top;
    size_a = a->size;
    size_b = b->size;
    while (current)
    {
        current->cost_b = current->pos;
        if (current->pos > size_b / 2)
            current->cost_b = (size_b - current->pos) * -1;
        current->cost_a = current->target;
        if (current->target > size_a / 2)
            current->cost_a = (size_a - current->target) * -1;
        current = current->next;
    }
}

void    execute_cheapest_move(t_stack *a, t_stack *b)
{
    t_node  *current;
    int     cheapest;
    int     cost_a;
    int     cost_b;

    current = b->top;
    cheapest = INT_MAX;
    while (current)
    {
        if (ft_abs(current->cost_a) + ft_abs(current->cost_b) < cheapest)
        {
            cheapest = ft_abs(current->cost_a) + ft_abs(current->cost_b);
            cost_a = current->cost_a;
            cost_b = current->cost_b;
        }
        current = current->next;
    }
    do_move(a, b, cost_a, cost_b);
}
