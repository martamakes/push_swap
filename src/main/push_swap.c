/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:33 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/03 09:28:01 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_stack(t_stack *stack_a)
{
    t_stack *stack_b;

    if (!stack_a || stack_a->size < 2)
        return ;
    
    //ft_printf("\n=== Initial state ===\n");
    //simple_print_stack(stack_a, "A");
    
    if (stack_a->size > 3)
        stack_b = init_stack();
    else
        stack_b = NULL;
    
    //ft_printf("\n=== Operations ===\n");
    if (stack_a->size == 2)
        sort_two(stack_a);
    else if (stack_a->size == 3)
        sort_three(stack_a);
    else if (stack_a->size <= 5)
        sort_five(stack_a, stack_b);
    else
        sort_large(stack_a, stack_b);
    
    //ft_printf("\n=== Final state ===\n");
    //simple_print_stack(stack_a, "A");
    
    if (stack_b)
        free_stack(stack_b);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;

    if (argc < 2)
        return (0);
    stack_a = parse_args(argc, argv);
    if (!stack_a)
        error_exit();
    sort_stack(stack_a);
    free_stack(stack_a);
    return (0);
}