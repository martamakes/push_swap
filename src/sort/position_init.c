/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:38:27 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 12:39:27 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    get_position(t_stack *stack)
{
    t_node  *current;
    int     i;

    current = stack->top;
    i = 0;
    while (current)
    {
        current->pos = i;
        current = current->next;
        i++;
    }
}

int    get_lowest_index_position(t_stack *stack)
{
    t_node  *current;
    int     lowest_index;
    int     lowest_pos;

    current = stack->top;
    lowest_index = INT_MAX;
    get_position(stack);
    lowest_pos = current->pos;
    while (current)
    {
        if (current->index < lowest_index)
        {
            lowest_index = current->index;
            lowest_pos = current->pos;
        }
        current = current->next;
    }
    return (lowest_pos);
}

static int    get_target(t_stack *a, int index_b, int target_index, int target_pos)
{
    t_node  *current;

    current = a->top;
    while (current)
    {
        if (current->index > index_b && current->index < target_index)
        {
            target_index = current->index;
            target_pos = current->pos;
        }
        current = current->next;
    }
    if (target_index != INT_MAX)
        return (target_pos);
    current = a->top;
    while (current)
    {
        if (current->index < target_index)
        {
            target_index = current->index;
            target_pos = current->pos;
        }
        current = current->next;
    }
    return (target_pos);
}

void    get_target_position(t_stack *a, t_stack *b)
{
    t_node  *current;
    int     target_pos;

    current = b->top;
    get_position(a);
    get_position(b);
    target_pos = 0;
    while (current)
    {
        target_pos = get_target(a, current->index, INT_MAX, target_pos);
        current->target = target_pos;
        current = current->next;
    }
}
