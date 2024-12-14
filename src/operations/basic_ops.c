/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvigara- <mvigara-@student.42school.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:09:17 by mvigara-          #+#    #+#             */
/*   Updated: 2024/12/14 17:28:03 by mvigara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_top(t_stack *stack)
{
    t_node *first;
    t_node *second;
    
    if (!stack || !stack->top || !stack->top->next)
        return ;
    first = stack->top;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    if (first == stack->bottom)
        stack->bottom = second;
    stack->top = second;
}

void    sa(t_stack *stack_a)
{
    swap_top(stack_a);
    ft_printf("sa\n");
}

void    sb(t_stack *stack_b)
{
    swap_top(stack_b);
    ft_printf("sb\n");
}

void    ss(t_stack *stack_a, t_stack *stack_b)
{
    swap_top(stack_a);
    swap_top(stack_b);
    ft_printf("ss\n");
}
