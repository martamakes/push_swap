/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:12:54 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:39:17 by mvigara-         ###   ########.fr       */
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
/* src/debug/test_ops.c */

void    test_rotations(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("\n=== Testing rotations ===\n");
    
    // Test initial state
    ft_printf("\nInitial state:\n");
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test ra
    ft_printf("\nExecuting ra:\n");
    ra(stack_a);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test rb
    ft_printf("\nExecuting rb:\n");
    rb(stack_b);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test rr
    ft_printf("\nExecuting rr:\n");
    rr(stack_a, stack_b);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
}

void    test_reverse_rotations(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("\n=== Testing reverse rotations ===\n");
    
    // Test initial state
    ft_printf("\nInitial state:\n");
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test rra
    ft_printf("\nExecuting rra:\n");
    rra(stack_a);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test rrb
    ft_printf("\nExecuting rrb:\n");
    rrb(stack_b);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
    
    // Test rrr
    ft_printf("\nExecuting rrr:\n");
    rrr(stack_a, stack_b);
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
}

void    test_all_operations(t_stack *stack_a, t_stack *stack_b)
{
    // Test swap operations first
    test_swaps(stack_a, stack_b);
    
    // Move some elements to stack_b for rotation tests if needed
    if (stack_b->size < 2)
    {
        ft_printf("\n=== Preparing stacks for rotation tests ===\n");
        pb(stack_a, stack_b);  // Move another element if needed
    }
    
    // Test all rotations
    test_rotations(stack_a, stack_b);
    test_reverse_rotations(stack_a, stack_b);
    
    ft_printf("\n=== Final state after all operations ===\n");
    simple_print_stack(stack_a, "a");
    simple_print_stack(stack_b, "b");
}
