/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:20:47 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/14 19:20:50 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int    find_position_for_value(t_stack *stack, int value)
{
    t_node  *current;
    int     pos;
    int     prev_value;

    if (!stack || !stack->top)
        return (0);
    current = stack->top;
    pos = 0;
    prev_value = stack->bottom->value;
    while (current)
    {
        if (value < current->value && value > prev_value)
            return (pos);
        prev_value = current->value;
        current = current->next;
        pos++;
    }
    return (get_min_pos(stack));
}

int    get_target_position(t_stack *a, int value)
{
    if (!a || !a->top)
        return (0);
    return (find_position_for_value(a, value));
}
