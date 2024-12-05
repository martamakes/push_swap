/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 11:20:11 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_stack *stack_a)
{
    if (!stack_a || stack_a->size != 2)
        return ;
    if (!is_sorted(stack_a))
        sa(stack_a);
}

void    sort_three(t_stack *stack_a)
{
    int highest_pos;

    if (!stack_a || stack_a->size != 3)
        return ;
    if (is_sorted(stack_a))
        return ;
    highest_pos = get_highest_pos(stack_a);
    if (highest_pos == 0)
        ra(stack_a);
    else if (highest_pos == 1)
        rra(stack_a);
    if (!is_sorted(stack_a))
        sa(stack_a);
}

static void    push_min_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int     min_pos;

    min_pos = get_min_pos(stack_a);
    while (min_pos != 0)
    {
        if (min_pos <= stack_a->size / 2)
            ra(stack_a);
        else
            rra(stack_a);
        min_pos = get_min_pos(stack_a);
    }
    pb(stack_a, stack_b);
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size > 5)
        return ;
    if (is_sorted(stack_a))
        return ;
    while (stack_a->size > 3)
        push_min_to_b(stack_a, stack_b);
    sort_three(stack_a);
    while (stack_b->size > 0)
        pa(stack_a, stack_b);
}
