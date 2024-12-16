/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 19:20:47 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 12:33:12 by mvigara-         ###   ########.fr       */
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

void    get_stack_position(t_stack *stack)
{
    t_node  *current;
    int     i;

    if (!stack)
        return ;
    current = stack->top;
    i = 0;
    while (current)
    {
        current->pos = i;
        current = current->next;
        i++;
    }
}

static int    get_target_position_value(t_stack *a, int value)
{
    t_node  *current;
    int     target_pos;
    int     min;
    int     max;

    get_stack_bounds(a, &min, &max);
    if (value > max || value < min)
        return (get_min_pos(a));
    current = a->top;
    target_pos = 0;
    while (current->next)
    {
        if (value > current->value && value < current->next->value)
            return (target_pos + 1);
        target_pos++;
        current = current->next;
    }
    return (0);
}

static void    calculate_target_positions(t_stack *a, t_stack *b)
{
    t_node  *current_b;
    int     target_pos;

    current_b = b->top;
    while (current_b)
    {
        target_pos = get_target_position_value(a, current_b->value);
        current_b->target = target_pos;
        current_b = current_b->next;
    }
}

void    get_target_position(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    get_stack_position(a);
    get_stack_position(b);
    calculate_target_positions(a, b);
}
