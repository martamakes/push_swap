/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:51:46 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:52:30 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_two(t_stack *stack_a)
{
    ft_printf("\nSort Two Numbers:\n");
    simple_print_stack(stack_a, "A");
    return ;
}

void    sort_three(t_stack *stack_a)
{
    ft_printf("\nSort Three Numbers:\n");
    simple_print_stack(stack_a, "A");
    return ;
}

void    sort_five(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("\nSort Five Numbers:\n");
    simple_print_stack(stack_a, "A");
    ft_printf("\nStack B created:\n");
    simple_print_stack(stack_b, "B");
    return ;
}
