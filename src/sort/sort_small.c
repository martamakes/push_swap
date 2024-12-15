/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/15 13:31:37 by mvigara-         ###   ########.fr       */
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

void    sort_three(t_stack *stack_a, char c)
{
    int max_pos;

    if (!stack_a || stack_a->size != 3 || is_sorted(stack_a))
        return ;
    
    max_pos = get_max_pos(stack_a);
    if (max_pos == 0)
    {
        rotate(stack_a);
        ft_printf("r%c\n", c);
    }
    else if (max_pos == 1)
    {
        reverse_rotate(stack_a);
        ft_printf("rr%c\n", c);
    }
    if (!is_sorted(stack_a))
    {
        swap_top(stack_a);
        ft_printf("s%c\n", c);
    }
}
