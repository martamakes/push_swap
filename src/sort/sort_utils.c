/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:58:45 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 09:35:22 by mvigara-         ###   ########.fr       */
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

t_chunk_info    *init_chunk_info(t_stack *stack)
{
    t_chunk_info *chunk;

    chunk = malloc(sizeof(t_chunk_info));
    if (!chunk)
        return (NULL);
    chunk->current = 0;
    chunk->total = stack->size <= 100 ? 5 : 11;
    get_chunk_limits(stack, 0, &chunk->start, &chunk->end);
    return (chunk);
}

void    free_chunk_info(t_chunk_info *chunk)
{
    free(chunk);
}

int get_value_at_position(t_stack *stack, int pos)
{
    t_node *current;
    int i;

    if (!stack || pos >= stack->size)
        return (0);
    current = stack->top;
    i = 0;
    while (current && i < pos)
    {
        current = current->next;
        i++;
    }
    return (current ? current->value : 0);
}
