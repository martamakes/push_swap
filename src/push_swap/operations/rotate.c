/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:11:29 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 17:12:00 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack, char stack_name)
{
    if (stack->size < 2)
        return;
    t_node *first = stack->top;
    t_node *last = stack->top;
    while (last->next)
        last = last->next;
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
    ft_printf("r%c\n", stack_name);
}
void ra(t_stack *a)
{
    rotate(a, 'a');
}

void rb(t_stack *b)
{
    rotate(b, 'b');
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a, 'a');
    rotate(b, 'b');
    ft_printf("rr\n");
}
