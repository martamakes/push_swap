/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:09:34 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 17:10:27 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack *stack, char stack_name)
{
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
    ft_printf("s%c\n", stack_name);
}

void sa(t_stack *a)
{
    swap(a, 'a');
}

void sb(t_stack *b)
{
    swap(b, 'b');
}
void ss(t_stack *a, t_stack *b)
{
    swap(a, 'a');
    swap(b, 'b');
    ft_printf("ss\n");
}
