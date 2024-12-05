/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:10:18 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 11:10:34 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void    get_stack_bounds(t_stack *stack, int *min, int *max)
{
    t_node  *current;

    if (!stack || !stack->top)
        return ;
    current = stack->top;
    *min = current->value;
    *max = current->value;
    while (current)
    {
        if (current->value < *min)
            *min = current->value;
        if (current->value > *max)
            *max = current->value;
        current = current->next;
    }
}

int    get_min_pos(t_stack *stack)
{
    t_node  *current;
    int     min;
    int     pos;
    int     min_pos;

    if (!stack || !stack->top)
        return (-1);
    current = stack->top;
    min = current->value;
    pos = 0;
    min_pos = 0;
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (min_pos);
}

int    get_max_pos(t_stack *stack)
{
    t_node  *current;
    int     max;
    int     pos;
    int     max_pos;

    if (!stack || !stack->top)
        return (-1);
    current = stack->top;
    max = current->value;
    pos = 0;
    max_pos = 0;
    while (current)
    {
        if (current->value > max)
        {
            max = current->value;
            max_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (max_pos);
}
