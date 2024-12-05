/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:20:20 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/05 09:16:24 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_node(t_stack *dst, t_stack *src)
{
    t_node *node_to_push;

    if (!src || !src->top)
        return ;

    // Remove node from source
    node_to_push = src->top;
    src->top = src->top->next;
    if (src->top)
        src->top->prev = NULL;
    src->size--;
    if (src->size == 0)
        src->bottom = NULL;

    // Add node to destination
    node_to_push->next = dst->top;
    if (dst->top)
        dst->top->prev = node_to_push;
    dst->top = node_to_push;
    node_to_push->prev = NULL;
    dst->size++;
    if (dst->size == 1)
        dst->bottom = node_to_push;
}

void    pa(t_stack *stack_a, t_stack *stack_b)
{
    push_node(stack_a, stack_b);
    ft_printf("pa\n");
}

void    pb(t_stack *stack_a, t_stack *stack_b)
{
    push_node(stack_b, stack_a);
    ft_printf("pb\n");
}
