/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:52:39 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:55:05 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_medium(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("\nSort Medium Stack:\n");
    simple_print_stack(stack_a, "A");
    ft_printf("\nStack B created:\n");
    simple_print_stack(stack_b, "B");
    return ;
}

void    sort_large(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("\nSort Large Stack:\n");
    simple_print_stack(stack_a, "A");
    ft_printf("\nStack B created:\n");
    simple_print_stack(stack_b, "B");
    return ;
}
