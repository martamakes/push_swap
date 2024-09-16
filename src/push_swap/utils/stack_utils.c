/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marta <marta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:45:27 by marta             #+#    #+#             */
/*   Updated: 2024/09/16 11:50:51 by marta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void free_node(t_node *node)
{
    if (node)
    {
        free(node);
    }
}

void free_stack(t_stack **stack)
{
    t_node *current;
    t_node *next;

    if (!stack || !*stack)
        return;

    current = (*stack)->top;
    while (current)
    {
        next = current->next;
        free_node(current);
        current = next;
    }
    free(*stack);
    *stack = NULL;
}

void free_stacks(t_stack **stack_a, t_stack **stack_b)
{
    free_stack(stack_a);
    free_stack(stack_b);
}
