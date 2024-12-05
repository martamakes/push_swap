/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:51:52 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:16:29 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int calculate_position_in_a(t_stack *a, int value)
{
    t_node  *current;
    int     position;
    int     min;
    int     max;
    
    get_stack_bounds(a, &min, &max);
    if (value > max || value < min)
        return (get_min_pos(a));
    current = a->top;
    position = 0;
    while (current->next)
    {
        if (value > current->value && value < current->next->value)
            return (position + 1);
        position++;
        current = current->next;
    }
    return (0);
}

void    calculate_target_position(t_stack *a, int value, t_cost *cost)
{
    t_node  *current;
    int     min;
    int     max;
    
    get_stack_bounds(a, &min, &max);
    if (value > max || value < min)
    {
        cost->pos_a = get_min_pos(a);
        return;
    }
    current = a->top;
    cost->pos_a = 0;
    while (current->next)
    {
        if (value > current->value && value < current->next->value)
            return;
        cost->pos_a++;
        current = current->next;
    }
    cost->pos_a = 0;
}
