/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:20:47 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/17 06:33:54 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* position_utils.c */

#include "push_swap.h"

int    get_position(t_stack *stack, int value)
{
    t_node  *current;
    int     pos;

    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    pos = 0;
    while (current)
    {
        if (current->value == value)
            return (pos);
        current = current->next;
        pos++;
    }
    return (0);
}

int    get_target_position_value(t_stack *stack, int value)
{
    t_node  *current;
    int     target_pos;
    int     closest_bigger;

    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    target_pos = 0;
    closest_bigger = INT_MAX;
    while (current)
    {
        if (current->value > value && current->value < closest_bigger)
        {
            closest_bigger = current->value;
            target_pos = get_position(stack, current->value);
        }
        current = current->next;
    }
    if (closest_bigger == INT_MAX)
        target_pos = get_min_pos(stack);
    return (target_pos);
}
