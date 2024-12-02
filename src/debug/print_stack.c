/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:52:29 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 07:55:39 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack, char *stack_name)
{
    t_node  *current;
    int     i;

    ft_printf("\n=== Stack %s Info ===\n", stack_name);
    if (!stack)
    {
        ft_printf("Stack is NULL!\n");
        return ;
    }

    ft_printf("Size: %d\n", stack->size);
    ft_printf("Top address: %p\n", (void *)stack->top);
    ft_printf("Bottom address: %p\n", (void *)stack->bottom);

    if (!stack->top)
    {
        ft_printf("Stack is empty\n");
        ft_printf("==================\n\n");
        return ;
    }

    ft_printf("\n--- Forward traversal ---\n");
    i = 0;
    current = stack->top;
    while (current)
    {
        ft_printf("Node[%d]:\n", i);
        ft_printf("  Address: %p\n", (void *)current);
        ft_printf("  Value: %d\n", current->value);
        ft_printf("  Prev: %p", (void *)current->prev);
        if (current->prev)
            ft_printf(" (value: %d)", current->prev->value);
        ft_printf("\n");
        ft_printf("  Next: %p", (void *)current->next);
        if (current->next)
            ft_printf(" (value: %d)", current->next->value);
        ft_printf("\n\n");
        current = current->next;
        i++;
    }

    ft_printf("--- Backward verification ---\n");
    current = stack->bottom;
    while (current)
    {
        ft_printf("Value: %d", current->value);
        if (current->prev)
            ft_printf(" <- ");
        current = current->prev;
    }
    ft_printf("\n==================\n\n");
}
