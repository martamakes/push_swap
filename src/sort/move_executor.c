/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:40:59 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/16 12:41:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
}

static void    rev_rotate_both(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}

static void    rotate_a(t_stack *a, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            ra(a);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rra(a);
            (*cost)++;
        }
    }
}

static void    rotate_b(t_stack *b, int *cost)
{
    while (*cost)
    {
        if (*cost > 0)
        {
            rb(b);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rrb(b);
            (*cost)++;
        }
    }
}

void    do_move(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        rev_rotate_both(a, b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        rotate_both(a, b, &cost_a, &cost_b);
    rotate_a(a, &cost_a);
    rotate_b(b, &cost_b);
    pa(a, b);
}
