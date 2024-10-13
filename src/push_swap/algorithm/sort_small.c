/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:03:03 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 17:03:15 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_three(t_stack *a)
{
    int top = a->top->value;
    int middle = a->top->next->value;
    int bottom = a->top->next->next->value;

    if (top > middle && middle < bottom && top < bottom)
        sa(a);
    else if (top > middle && middle > bottom)
    {
        sa(a);
        rra(a);
    }
    else if (top > middle && middle < bottom && top > bottom)
        ra(a);
    else if (top < middle && middle > bottom && top < bottom)
    {
        sa(a);
        ra(a);
    }
    else if (top < middle && middle > bottom && top > bottom)
        rra(a);
}

static void sort_small(t_stack *a, t_stack *b)
{
    int size = a->size;

    if (size == 2 && a->top->value > a->top->next->value)
        sa(a);
    else if (size == 3)
        sort_three(a);
    else
    {
        while (a->size > 3)
        {
            // Find the smallest number and push it to b
            int min_pos = find_min_position(a);
            while (min_pos > 0)
            {
                ra(a);
                min_pos--;
            }
            pb(a, b);
        }
        sort_three(a);
        while (b->size > 0)
            pa(b, a);
    }
}

void sort(t_stack *a, t_stack *b)
{
    if (a->size <= 5)
        sort_small(a, b);
    else
        sort_large(a, b);
}