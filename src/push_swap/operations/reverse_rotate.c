/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:12:19 by marta             #+#    #+#             */
/*   Updated: 2024/10/13 17:12:50 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack *stack, char stack_name)
{
    if (stack->size < 2)
        return;
    t_node *last = stack->top;
    t_node *prev = NULL;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = stack->top;
    stack->top = last;
    ft_printf("rr%c\n", stack_name);
}
void rra(t_stack *a)
{
    reverse_rotate(a, 'a');
}

void rrb(t_stack *b)
{
    reverse_rotate(b, 'b');
}

void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a, 'a');
    reverse_rotate(b, 'b');
    ft_printf("rrr\n");
}
