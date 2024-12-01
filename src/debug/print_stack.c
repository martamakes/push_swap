/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:52:29 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 17:51:20 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack, char *stack_name)
{
    int i;

    ft_printf("\n=== Stack %s ===\n", stack_name);
    if (!stack)
    {
        ft_printf("(empty)\n");
        return ;
    }
    
    i = 0;
    while (stack)
    {
        ft_printf("[%d]: %d\n", i++, stack->value);
        stack = stack->next;
    }
    ft_printf("=============\n\n");
}