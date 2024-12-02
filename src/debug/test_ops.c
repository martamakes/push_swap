/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:12:54 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:24:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    test_swaps(t_stack *stack_a, t_stack *stack_b)
{
    // Move some nodes to stack_b first
    ft_printf("\n=== Moving nodes to stack b ===\n");
    pb(stack_a, stack_b);  // Move first number to b
    pb(stack_a, stack_b);  // Move second number to b
    
    ft_printf("\nState after moving nodes to b:\n");
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");

    // Now test swaps
    ft_printf("\n=== Testing swaps ===\n");
    
    // Test sa
    ft_printf("\nExecuting sa:\n");
    sa(stack_a);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test sb
    ft_printf("\nExecuting sb:\n");
    sb(stack_b);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test ss
    ft_printf("\nExecuting ss:\n");
    ss(stack_a, stack_b);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
}
