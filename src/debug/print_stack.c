/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:52:29 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/01 18:23:00 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack, char *stack_name)
{
    t_node *current;
    int    i;

    ft_printf("\n=== Stack %s ===\n", stack_name);
    if (!stack || !stack->top)
    {
        ft_printf("(empty)\n");
        return ;
    }
    
    i = 0;
    current = stack->top;
    while (current)
    {
        ft_printf("[%d]: %d\n", i++, current->value);
        current = current->next;
    }
    ft_printf("=============\n\n");
}