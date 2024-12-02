/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 09:08:23 by mvigara-         ###   ########.fr       */
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

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || !stack_b || stack_a->size > 5)
        return ;
    // TODO: Implement five numbers sort algorithm
}
