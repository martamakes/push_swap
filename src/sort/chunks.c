/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:42:25 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 15:50:24 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_chunk_size(int stack_size)
{
    if (stack_size <= 100)
        return (20);
    return (50);
}

int get_chunk_max(t_stack *stack, int chunk_size, int chunk_num)
{
    int max_value;
    int count;
    t_node *current;

    max_value = INT_MIN;
    count = 0;
    current = stack->top;
    while (current && count < chunk_size * chunk_num)
    {
        if (current->value > max_value)
            max_value = current->value;
        current = current->next;
        count++;
    }
    return (max_value);
}

int is_in_chunk(int value, int min, int max)
{
    return (value >= min && value <= max);
}

int find_closest_chunk_num(t_stack *stack, int chunk_min, int chunk_max)
{
    t_node *current;
    int pos;
    int closest_pos;

    pos = 0;
    closest_pos = -1;
    current = stack->top;
    while (current)
    {
        if (is_in_chunk(current->value, chunk_min, chunk_max))
        {
            if (closest_pos == -1 || pos < closest_pos)
                closest_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return (closest_pos);
}
