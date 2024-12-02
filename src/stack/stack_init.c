/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:46:40 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/02 07:50:08 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        error_exit();
    stack->top = NULL;
    stack->size = 0;
    stack->bottom = NULL;
    return (stack);
}

t_node *create_node(int value)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        error_exit();
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    ft_printf("Debug: Node created - value: %d, address: %p\n", value, (void*)new);
    return (new);
}
