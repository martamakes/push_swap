/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 08:24:27 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc < 2)
        return (0);
    
    stack_a = parse_args(argc, argv);
    if (!stack_a)
        error_exit();
    
    stack_b = NULL;
    if (stack_a->size > 3)
    {
        stack_b = init_stack();
        if (!stack_b)
        {
            free_stack(stack_a);
            error_exit();
        }
    }

    ft_printf("\n=== Initial state ===\n");
    simple_print_stack(stack_a, "a");
    if (stack_b)
        simple_print_stack(stack_b, "b");

    if (stack_b)
        test_swaps(stack_a, stack_b);
    else
        ft_printf("\nStack has 3 or fewer elements - skipping swap tests\n");

    if (stack_b)
        free_stack(stack_b);
    free_stack(stack_a);
    return (0);
}