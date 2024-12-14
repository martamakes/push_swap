/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:51:52 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 13:48:49 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
