/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:58:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 04:57:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_node *current;

    if (!stack || !stack->top || !stack->top->next)
        return (1);
    current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int get_highest_pos(t_stack *stack)
{
    t_node  *current;
    int     highest;
    int     pos;
    int     highest_pos;

    if (!stack || !stack->top)
        return (-1);
    current = stack->top;
    highest = current->value;
    pos = 0;
    highest_pos = 0;
    while (current)
    {
        if (current->value > highest)
        {
            highest = current->value;
            highest_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return (highest_pos);
}

void    rotate_to_min(t_stack *a)
{
    int min_pos;
    int size;

    if (!a || a->size < 2)
        return ;
    min_pos = get_min_pos(a);
    size = a->size;
    if (min_pos == 0)
        return ;
    if (min_pos <= size / 2)
    {
        while (min_pos > 0)
        {
            ra(a);
            min_pos--;
        }
    }
    else
    {
        while (min_pos < size)
        {
            rra(a);
            min_pos++;
        }
    }
}
